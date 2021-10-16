#ifndef MAP_HPP
# define MAP_HPP

#include "extras.hpp"
#include "Iterator.hpp"

namespace ft
{
	template<
    class Key,
    class T,
    class Compare = ft::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {
		public :
			typedef	treeNode<Key, T> *			node_ptr;
			typedef	treeNode<Key, T>			node;
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef ft::pair<Key, T>			value_type;
			typedef Compare						key_compare;
			typedef std::allocator<value_type>	allocator_type;
			typedef	allocator_type&				reference;
			typedef	reference					const_reference;
			typedef allocator_type*				pointer;
			typedef pointer						const_pointer;
			typedef	mapIterator<Key, T>			iterator;
			typedef mapConstIterator<Key, T>	const_iterator;
			typedef mapRevIterator<Key, T>		reverse_iterator;
			typedef mapConstRevIterator<Key, T>	const_reverse_iterator;
			typedef ptrdiff_t					difference_type;
			typedef size_t						size_type;

		private :
			node_ptr					_root;
			size_type					_size;
			key_compare					_comp;
			allocator_type				_all;

		public :
			explicit map( const key_compare& comp = key_compare(),
			const Allocator& alloc = Allocator()) : _root(NULL), _size(0), _comp(comp), _all(alloc) {};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<InputIterator::InputIter, InputIterator>::type = NULL) : _root(NULL), _size(0), _comp(comp), _all(alloc) {};

			map (const map& x) : _root(NULL), _size(0)
			{
				*this = x;
			}

			virtual ~map()
			{

			}

			iterator begin()
			{
				iterator cur(_root);
				return (cur.leftmost());
			}

			const_iterator begin() const
			{
				const_iterator cur(_root);
				return (cur.leftmost());
			}

			iterator end()
			{
				iterator cur(_root);
				return (++(cur.rightmost()));
			}

			const_iterator end() const
			{
				const_iterator cur(_root);
				return (++(cur.rightmost()));
			}

			reverse_iterator rbegin()
			{
				reverse_iterator cur(_root);
				return (cur.rightmost());
			}

			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator cur(_root);
				return (cur.rightmost());
			}

			reverse_iterator rend()
			{
				reverse_iterator cur(_root);
				return (--(cur.leftmost()));
			};

			const_reverse_iterator rend() const;

			bool empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			size_type size() const
			{
				return (_size);
			}

			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max() / sizeof(T));
			}

			mapped_type& operator[] (const key_type& k)
			{
				node_ptr	found = find_node(k);

				if (_size == 0)
				{
					value_type	new_root(value_type(k, mapped_type()));
					_size++;
					node_ptr	new_node = new node(new_root);
					_root = new_node;
					return (_root->get_value());
				}
				if (found->get_key() == k)
					return (found->get_value());
				else
				{
					value_type	new_node(value_type(k, mapped_type()));
					_size++;
					return (insert_node(found, new_node)->get_value());
				}
				
				return (_root->get_value());
			}

			pair<iterator,bool> insert (const value_type& val)
			{
				node_ptr found = find_node(val.first);
				if (_size == 0)
					(*this)[val.first] = val.second;
				else if (found->get_key() == val.first)
				{
					iterator	it(found);
					return (pair<iterator, bool>(it, false));
				}
				else
				{
					(*this)[val.first] = val.second;
					iterator it(find_node(val.first));
					return (pair<iterator, bool>(it, true));
				}
				return (pair<iterator, bool>(begin(), true));
			};

			iterator insert (iterator position, const value_type& val)
			{
				if (_size == 0)
					return (insert(val).first);
				if (_size > 0 && find_node(val.first)->get_key() != val.first)
				{
					value_type tmp = val;
					insert_node(find_node((*position).first), tmp);
				}
				iterator it2(find_node(val.first));
				return (it2);
			};

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,
			typename ft::enable_if<InputIterator::InputIter, InputIterator>::type = NULL)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void erase (iterator position);

			size_type erase (const key_type& k);

			void erase (iterator first, iterator last);

			void clear();

			key_compare key_comp() const;

			iterator find (const key_type& k);

			const_iterator find (const key_type& k) const;

			iterator lower_bound (const key_type& k);

			const_iterator lower_bound (const key_type& k) const;

			iterator upper_bound (const key_type& k);

			const_iterator upper_bound (const key_type& k) const;

			pair<iterator,iterator>				equal_range (const key_type& k);

			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const;

			class value_compare :
			public binary_function<value_type, value_type, bool>
			{
				protected :
					Compare comp;

				public :
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}

			};

			value_compare value_comp() const { return (value_compare(Compare())); };

		private :

			node_ptr	find_node(const key_type &k)
			{
				node_ptr cur = _root;

				while (cur != NULL && cur->get_key() != k)
				{
					if (_comp(k, cur->get_key()))
					{
						if (cur->get_left() != NULL)
							cur = cur->get_left();
						else
							return (cur);
					}
					else
					{
						if (cur->get_right() != NULL)
							cur = cur->get_right();
						else
							return (cur);
					}
				}
				return (cur);
			}

			node_ptr	insert_node(node_ptr root, value_type &k)
			{
				if (_comp(k.first, root->get_key()))
				{
					if (root->get_left() != NULL)
						insert_node(root->get_left(), k);
					else
					{
						node_ptr 	inser = new node (k);
						root->set_left(inser);
						inser->set_root(root);
						return (inser);
					}
				}
				else
				{
					if (root->get_right() != NULL)
						insert_node(root->get_right(), k);
					else
					{
						node_ptr 	inser = new node (k);
						root->set_right(inser);
						inser->set_root(root);
						return (inser);
					}
				}
				return (NULL);
			}
    };
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:55:12 by adjemaa           #+#    #+#             */
/*   Updated: 2021/11/15 17:36:38 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "extras.hpp"
#include "Iterator.hpp"
#include "stack.hpp"

namespace ft
{
	template<
    class Key,
    class T,
    class Compare = ft::less<Key>,
    class Allocator = std::allocator<treeNode<Key, T> > >
    class map
    {
		public :
			typedef	treeNode<Key, T> *			node_ptr;
			typedef	treeNode<Key, T>			node;
			typedef Key							key_type;
			typedef T							mapped_type;
			typedef ft::pair<Key, T>			value_type;
			typedef Compare						key_compare;
			typedef std::allocator<node>		allocator_type;
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
			bool						_empty;
			allocator_type				_all;

		public :
			explicit map( const key_compare& comp = key_compare(),
			const Allocator& alloc = Allocator()) : _root(NULL), _size(0), _comp(comp), _empty(true), _all(alloc)	 {
				_size = 0;
				_empty = true;
			};

			template <typename InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename enable_if<!(is_integral<InputIterator>::value), InputIterator>::type = NULL) : _root(NULL), _size(0), _comp(comp), _all(alloc)
			{
				insert(first, last);
			}
			map	&operator=(const map &cpy)
			{
				if (_size != 0)
					this->clear();
				if (cpy.size() != 0)
				{
					insert(cpy.begin(), cpy.end());
				}
				return (*this);
			}
			map (map const &cpy) : _root(NULL), _size(0), _comp(key_compare()), _all(allocator_type())
			{
				*this = cpy;
			}

			virtual ~map()
			{
				clear();
			}

			iterator begin()
			{
				if (_size == 0)
					return (end());
				iterator cur(_root);
				return (cur.leftmost());
			}

			const_iterator begin() const
			{
				if (_size == 0)
					return (end());
				const_iterator cur(_root);
				return (cur.leftmost());
			}

			iterator end()
			{
				node_ptr	tmp;
				tmp = _root;
				iterator cur(tmp);
				if (_size == 0)
					return (cur);
				return (++(cur.rightmost()));
			}

			const_iterator end() const
			{
				node_ptr	tmp;
				tmp = _root;
				const_iterator cur(tmp);
				if (_size == 0)
					return (cur);
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
				return (++(cur.leftmost()));
			};

			const_reverse_iterator rend() const
			{
				const_reverse_iterator cur(_root);
				return (++(cur.leftmost()));
			};

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
					node_ptr	new_node = _all.allocate(1);
					_all.construct(new_node, node(new_root));
					_root = new_node;
					_rightmost = _root;
					_leftmost = _root;
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
				{
					(*this)[val.first] = val.second;

				}
				else if (found->get_key() == val.first)
				{
					iterator	it(found);
					return (pair<iterator, bool>(it, false));
				}
				else
				{
					iterator it(insert_node(_root, val));
					_size++;
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
					_size++;
					insert_node(find_node((*position).first), tmp);
				}
				iterator it2(find_node(val.first));
				return (it2);
			};

			template <typename InputIterator>
			void insert (InputIterator first, InputIterator last,
			typename enable_if<!(is_integral<InputIterator>::value), InputIterator>::type = NULL)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			T& at( const Key& key )
			{
				node_ptr to_find;

				to_find = find_node(key);
				if (to_find->get_key() == key)
					return (to_find);
				else
					throw (std::out_of_range("out of range"));
			}
			void erase (iterator position)
			{
				node_ptr to_erase = find_node((*position).first);
				if (_size == 1)
				{
					_all.destroy(to_erase);
					_all.deallocate(to_erase, 1);
					_size--;
					return ;
				}
				if (to_erase->get_right() == NULL && to_erase->get_left() == NULL)
				{
					if (to_erase->get_root()->get_right() == to_erase)
						to_erase->get_root()->set_right(NULL);
					else if (to_erase->get_root()->get_left() == to_erase)
						to_erase->get_root()->set_left(NULL);
					_all.destroy(to_erase);
					_all.deallocate(to_erase, 1);
					_size--;
				}
				else if (to_erase->get_left() == NULL)
				{
					if (to_erase == _root)
					{
						_root = to_erase->get_right();
						to_erase->get_right()->set_root(NULL);
					}
					else if (to_erase->get_root()->get_right() == to_erase)
					{
						to_erase->get_root()->set_right(to_erase->get_right());
						to_erase->get_right()->set_root(to_erase->get_root());
					}
					else
					{
						to_erase->get_root()->set_left(to_erase->get_right());
						to_erase->get_right()->set_root(to_erase->get_root());
					}
					_all.destroy(to_erase);
					_all.deallocate(to_erase, 1);
					_size--;
				}
				else if (to_erase->get_right() == NULL)
				{
					if (to_erase->get_root()->get_right() == to_erase)
					{
						to_erase->get_root()->set_right(to_erase->get_left());
						to_erase->get_left()->set_root(to_erase->get_root());
					}
					else
					{
						to_erase->get_root()->set_left(to_erase->get_left());
						to_erase->get_left()->set_root(to_erase->get_root());
					}
					_all.destroy(to_erase);
					_all.deallocate(to_erase, 1);;
					_size--;
				}
				else
				{
					node_ptr succ;
					node_ptr succParent;

					succParent = to_erase;
					succ = to_erase->get_right();

					while (succ->get_left() != NULL)
					{
						succParent = succ;
						succ = succ->get_left();
					}
					if (succParent != to_erase)
					{
						succParent->set_left(succ->get_right());
						succParent->get_left()->set_root(succParent);
					}
					else
					{
						succParent->set_right(succ->get_right());
						succParent->get_right()->set_root(succParent);
					}
					to_erase->set_pair(succ->get_pair());
					_all.destroy(succ);
					_all.deallocate(succ, 1);
					_size--;
				}

			}

			size_type erase (const key_type& k)
			{
				iterator it(find_node(k));

				if ((it)->first == k)
					erase(it);
				return (0);
			}

			void erase (iterator first, iterator last)
			{
				ft::stack<key_type> keys;
				while (first != last)
				{
					keys.push(first->first);
					first++;
				}
				while (keys.empty() == false)
				{
					erase(keys.top());
					keys.pop();
				}

			}

			void clear()
			{
				while(_size != 0)
					erase(begin());
			}

			key_compare key_comp() const
			{
				return (key_compare());
			}

			iterator find (const key_type& k)
			{
				node_ptr it(find_node(k));

				if (it->get_key() != k)
					return (end());
				return (iterator(it));
			}

			const_iterator find (const key_type& k) const
			{
				node_ptr it(find_node(k));

				if (it->get_key() != k)
					return (end());
				return (const_iterator(it));
			}

			iterator lower_bound (const key_type& k)
			{
				iterator it = begin();

				while (_comp((*it).first, k) && it != end())
					it++;
				return (it);
			}

			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it = begin();

				while (_comp((*it).first, k) && it != end())
					it++;
				return (it);
			}

			iterator upper_bound (const key_type& k)
			{
				iterator it = lower_bound(k);

				if ((*it).first == k && it != end())
					it++;
				return (it);
			}

			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it = lower_bound(k);

				if ((*it).first == k && it != end())
					it++;
				return (it);
			}

			pair<iterator,iterator>				equal_range (const key_type& k)
			{
				return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
			{
				return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}
			size_type count(const key_type& key) const
			{
				node_ptr it(find_node(key));

				if (it->get_key() != key)
					return (0);
				return (1);
			}
			class value_compare :
			public binary_function<value_type, value_type, bool>
			{
				protected :
					Compare comp;

				public :
					value_compare(Compare c) : comp(c) {};
					virtual ~value_compare() {};
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}

			};

			value_compare value_comp() const { return (value_compare(Compare())); };


			void swap (map& x)
			{
				node_ptr					tm_root = _root;
				size_type					tm_size  = _size;
				key_compare					tm_comp = _comp;
				bool						tm_empty = _empty;
				allocator_type				tm_all = _all;
				node_ptr					tm_rightmost = _rightmost;
				node_ptr					tm_leftmost = _leftmost;
	

				_root = x._root;
				_size = x._size;
				_comp = x._comp;
				_empty = x._empty;
				_all = x._all;
				_rightmost = x._rightmost;
				_leftmost = x._leftmost;

				x._root = tm_root;
				x._size = tm_size;
				x._comp = tm_comp;
				x._empty = tm_empty;
				x._all = tm_all;
				x._rightmost = tm_rightmost;
				x._leftmost = tm_leftmost;

			}

		private :
			node_ptr _rightmost;
			node_ptr _leftmost;

			node_ptr	find_node(const key_type &k) const
			{
				node_ptr cur = _root;

				while (_size > 0 && cur != NULL && cur->get_key() != k)
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

			node_ptr	insert_node(node_ptr root, const value_type &k)
			{
				int	inserted = 0;

				if (_size > 0 && _comp(k.first, _leftmost->get_key()))
				{
					node_ptr 	inser = _all.allocate(1);
					_all.construct(inser, node(k));
					_leftmost->set_left(inser);
					inser->set_root(_leftmost);
					_leftmost = inser;
					inserted = 1;
					return (inser);
				}
				if (_size > 0 && _comp(_rightmost->get_key(), k.first))
				{
					node_ptr 	inser = _all.allocate(1);
					_all.construct(inser, node(k));
					_rightmost->set_right(inser);
					inser->set_root(_rightmost);
					_rightmost = inser;
					inserted = 1;
					return (inser);
				}
				while (inserted == 0)
				{
					if (_comp(k.first, root->get_key()))
					{
						if (root->get_left() != NULL)
							root = root->get_left();
						else
						{
							node_ptr 	inser = _all.allocate(1);
							_all.construct(inser, node(k));
							root->set_left(inser);
							inser->set_root(root);
							inserted = 1;
							return (inser);
						}
					}
					else
					{
						if (root->get_right() != NULL)
							root = root->get_right();
						else
						{
							node_ptr 	inser = _all.allocate(1);
							_all.construct(inser, node(k));
							root->set_right(inser);
							inser->set_root(root);
							inserted = 1;
							return (inser);
						}
					}
				}
				return (NULL);
			}
    };
	template< class Key, class T, class Compare, class Alloc >
	bool operator==(const 	map<Key,T,Compare,Alloc>& lhs,
                 	const 	map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() == rhs.size())
		{
			typename ft::map<Key, T>::iterator it = lhs.begin();
			typename ft::map<Key, T>::iterator it2 = rhs.begin();
			while(*it == *it2 && it != lhs.end() && it2 != rhs.end())
			{
				it++;
				it2++;
			}
			if (it == lhs.end() && it2 == rhs.end())
				return (true);
			return (false);
		}
		else
			return (false);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=(const 	map<Key,T,Compare,Alloc>& lhs,
                 	const 	map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<(const 	map<Key,T,Compare,Alloc>& lhs,
                 	const 	map<Key,T,Compare,Alloc>& rhs )
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>(const 	map<Key,T,Compare,Alloc>& lhs,
                 	const 	map<Key,T,Compare,Alloc>& rhs )
	{
		return (lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=(const 	map<Key,T,Compare,Alloc>& lhs,
                 	const 	map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs == rhs)
			return (true);
		return (lhs < rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(const 	map<Key,T,Compare,Alloc>& lhs,
                 	const 	map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs == rhs)
			return (true);
		return (lhs > rhs);
	}
}

#endif

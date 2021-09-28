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
			treeNode<Key, T> *			_node_ptr;
			size_type					_size;
			key_compare					_comp;
			allocator_type				_all;

		public :
			explicit map( const Compare& comp,
			const Allocator& alloc = Allocator()) : _node_ptr(NULL), _size(0), _comp(comp), _all(alloc) {};

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<InputIterator::InputIter, InputIterator>::type = NULL) : _node_ptr(NULL), _size(0), _comp(comp), _all(alloc) {};

			map (const map& x) : _node_ptr(NULL), _size(0)
			{
				*this = x;
			}

			virtual ~map();

			iterator begin()
			{
				iterator cur(_node_ptr);
				return (cur.leftmost());
			}

			const_iterator begin() const
			{
				const_iterator cur(_node_ptr);
				return (cur.leftmost());
			}

			iterator end();

			const_iterator end() const;

			reverse_iterator rbegin();

			const_reverse_iterator rbegin() const;

			reverse_iterator rend();

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
    };
}

#endif

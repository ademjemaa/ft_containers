#ifndef EXTRAS_HPP
# define EXTRAS_HPP

# include <stdio.h>
# include <sstream>
#include <iostream>

namespace ft{

    //https://www.boost.org/doc/libs/1_63_0/boost/type_traits/integral_constant.hpp
	template <typename T, bool val>
	struct is_integral_val
	{
		typedef T type;
		static const bool value = val;
	};
	template <typename> struct is_integral_type : is_integral_val<bool, false>{};
	template <> struct is_integral_type<bool> : is_integral_val<bool, true>{};
	template <> struct is_integral_type<char> : is_integral_val<char, true>{};
	template <> struct is_integral_type<signed char> : is_integral_val<signed char, true>{};
	template <> struct is_integral_type<short int> : is_integral_val<short int, true>{};
	template <> struct is_integral_type<int> : is_integral_val<int, true>{};
	template <> struct is_integral_type<long int> : is_integral_val<long int, true>{};
	template <> struct is_integral_type<long long int> : is_integral_val<long long int, true>{};
	template <> struct is_integral_type<unsigned char> : is_integral_val<unsigned char, true>{};
	template <> struct is_integral_type<unsigned short int> : is_integral_val<unsigned short int, true>{};
	template <> struct is_integral_type<unsigned int> : is_integral_val<unsigned int, true>{};
	template <> struct is_integral_type<unsigned long int> : is_integral_val<unsigned long int, true>{};
	template <> struct is_integral_type<unsigned long long int> : is_integral_val<unsigned long long int, true>{};
	//https://www.boost.org/doc/libs/1_63_0/boost/type_traits/is_integral.hpp
    template <typename T> struct is_integral : public is_integral_type<T>
	{
	};

    //enable_if : https://en.cppreference.com/w/cpp/types/enable_if
    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T>
        {
            typedef T type;
        };
    //lexicographical_compare https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    template<class InputIt1, class InputIt2>
        bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
        {
            for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
            {
                if (*first1 < *first2) return true;
                if (*first2 < *first1) return false;
            }
            return (first1 == last1) && (first2 != last2);
        }
    template <typename T1, typename T2>
    class pair
    {
        public :
            T1  first;
            T2  second;

            //https://en.cppreference.com/w/cpp/utility/pair/pair
            pair()
            {
            };
            pair( const T1& x, const T2& y ) : first(x), second(y)  {};
            template< class U1, class U2 >
            pair( const pair<U1, U2>& p)
            {
                this->first = p.first;
                this->second = p.second;
            }
            //https://en.cppreference.com/w/cpp/utility/pair/operator%3D
            template<class U1, class U2>
            pair& operator=( const pair<U1, U2>& other )
            {
                this->first = other.first;
                this->second = other.second;
                return (*this);
            }
    };

    template<class T1, class T2>
    bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template< class T1, class T2 >
    bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template< class T1, class T2 >
    bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        if (lhs.first < rhs.first)
            return (true);
        else if (rhs.first < lhs.first)
            return (false);
        else if (lhs.second < rhs.second)
            return (true);
        else
            return (false);
    }

    template< class T1, class T2 >
    bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return(!(rhs < lhs));
    }

    template< class T1, class T2 >
    bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }

    template< class T1, class T2 >
    bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
    {
        return (!(lhs < rhs));
    }

    template< typename T1, typename T2 >
    pair<T1,T2> make_pair( T1 t, T2 u )
    {
        return(ft::pair<T1, T2>(t, u));
    }

    template <typename T1, typename T2>
    std::ostream& operator <<(std::ostream& str, ft::pair<T1, T2>& p)
    {
        str << "first : ";
        str << p.first;
        str << " second : ";
        str << p.second;
        return str;
    }
    //binary function https://en.cppreference.com/w/cpp/utility/functional/binary_function

    template<
    class Arg1,
    class Arg2,
    class Result>
    struct binary_function
    {
        typedef Arg1    first_argument_type;
        typedef Arg2    second_argument_type;
        typedef Result  result_type;
    };

    //std::less https://en.cppreference.com/w/cpp/utility/functional/less

    template<typename T>
		struct less :
        public binary_function<T, T, bool>
		{
			bool operator()( const T& lhs, const T& rhs ) const
			{
				return (lhs < rhs);
			}
		};

    template<typename T1, typename T2>
    class treeNode
    {
        public :
            typedef ft::pair<T1, T2>    pair;
            typedef treeNode<T1, T2> *  pointer;
            typedef treeNode<T1, T2>    node;
        private :
            pair		_pair;
            pointer		_root;
            pointer		_left;
            pointer		_right;
        public :
            treeNode(void) : _root(NULL), _left(NULL), _right(NULL) {};
            treeNode(pair const &pair) : _pair(pair),_root(NULL), _left(NULL), _right(NULL) {};
            treeNode(treeNode const &cpy)
            {
                *this = cpy;
            }
            treeNode &operator=(treeNode const &cpy)
            {
                _pair = cpy._pair;
                _root = cpy._root;
                _left = cpy._left;
                _right = cpy._right;
                return (*this);
            }

            virtual ~treeNode() {};
            pointer get_root(void) {return (_root);};
            pointer get_left(void) {return (_left);};
            pointer get_right(void) {return (_right);};
            T1      &get_key(void) {return (_pair.first);};
            T2      &get_value(void) {return (_pair.second);};
            pair    &get_pair(void) {return (_pair);};

            void    set_root(pointer node) {_root = node;};
            void    set_left(pointer node) {_left = node;};
            void    set_right(pointer node) {_right = node;};
            void    set_pair(pair pr) {_pair = pr; }

            pointer leftmost(pointer node)
            {
                pointer current = node;

                while (current->_left != NULL)
                    current = current->_left;
                return (current);
            }

            pointer rightmost(pointer node)
            {
                pointer current = node;

                while (current->_right != NULL)
                    current = current->_right;
                return (current);
            }
    };

    template <typename Tkey, typename Tvalue >
    class	mapIterator
    {
        public:
            typedef treeNode<Tkey, Tvalue>	        node;
            typedef node *					        ptr;
            typedef ft::pair<Tkey, Tvalue>	        value_type;
            typedef value_type &	                reference;
            typedef value_type *	                pointer;
		protected :
			ptr										_ptr;
            ptr                                     _root;
            bool									_end;
		public :
			mapIterator(void) : _ptr(NULL), _root(NULL) ,_end(false) {};
			mapIterator(ptr ptr) {_ptr = ptr; _end = false; _root = ptr;}
			mapIterator(const mapIterator &cpy)
            {
                if (cpy._end == true)
                    _ptr = new node(*(cpy._ptr));
                else
                    _ptr = cpy._ptr;
                _root = cpy._root;
                _end = cpy._end;
            }
			virtual ~mapIterator()
            {
                if (_end == true)
                    delete _ptr;
            }

			mapIterator &operator=(mapIterator const &cpy)
            {
                if (cpy._end == true)
                {
                    if (_end == true)
                       delete _ptr;
                    _ptr = new node(*(cpy._ptr));
                }
                else
                    _ptr = cpy._ptr;
                _end = cpy._end;
                _root = cpy._root;
                return (*this);
            }
			// ++/-- operations in binary tree
			//https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
			mapIterator operator ++()
			{
                ptr tmp;
                tmp = _ptr;

                if (_root->rightmost(_root) == tmp)
                {
                    ptr bot = new node();
					bot->set_root(_ptr);
					_ptr = bot;
                    _end = true;
                    return (*this);
                }
				else if (_ptr->get_right())
                {
					_ptr = _ptr->leftmost(_ptr->get_right());
                    _end = false;
                    return (*this);
                }
				else if (_end == false)
				{
					ptr p = _ptr->get_root();
					while (p && _ptr == p->get_right())
					{
						_ptr = p;
						p = p->get_root();
					}
					_ptr = p;
				}
				return (*this);
			}
			mapIterator operator --()
			{
                if (_end == true)
                {
                    ptr tmp = _ptr;
                    _ptr = _ptr->get_root();
                    _end = false;
                    delete tmp;
                    return (*this);
                }
				if (_ptr->get_left())
				{
					_ptr = _ptr->get_left();
					while (_ptr->get_right())
						_ptr = _ptr->get_right();
				}
				else
					_ptr = _ptr->get_root();
				return (*this);
			}

			mapIterator operator++(int)
			{
				mapIterator before = *this;
				++(*this);
				return (before);
			}

			mapIterator operator--(int)
			{
				mapIterator before = *this;
				--(*this);
				return (before);
			}

			reference operator*()
			{
				return (_ptr->get_pair());
			}

			pointer operator->()
			{
				return (&(_ptr->get_pair()));
			}

			bool operator==(mapIterator const &cmp)
			{
				if (_end == true && cmp._end == true)
					return (true);
				return (_ptr->get_key() == cmp._ptr->get_key());
			}

            bool operator!=(mapIterator const &cmp)
			{
				return (!(*this == cmp));
			}

			mapIterator leftmost()
			{
				while (_ptr->get_left() != NULL)
                    _ptr = _ptr->get_left();
				return (*this);
			}

			mapIterator rightmost()
			{
				while (_ptr->get_right() != NULL)
                    _ptr = _ptr->get_right();
				return (*this);
			}

            static const bool InputIter = true;
	};
	template <typename Tkey, typename Tvalue >
    class	mapConstIterator
	{
        public:
            typedef treeNode<Tkey, Tvalue>	        node;
            typedef node *					        ptr;
            typedef ft::pair<Tkey, Tvalue>	        value_type;
            typedef value_type &	                reference;
            typedef value_type const &              constReference;
            typedef value_type *	                pointer;
		protected :
			ptr										_ptr;
            ptr                                     _root;
            bool									_end;
		public :
			mapConstIterator(void) : _ptr(NULL), _root(NULL) ,_end(false) {};
			mapConstIterator(ptr ptr) {
            _ptr = ptr; _end = false; _root = ptr;}
			mapConstIterator(const mapConstIterator &cpy)
            {
                if (cpy._end == true)
                    _ptr = new node(*(cpy._ptr));
                else
                    _ptr = cpy._ptr;
                _root = cpy._root;
                _end = cpy._end;
            }
			virtual ~mapConstIterator()
            {
                if (_end == true)
                    delete _ptr;
            }

			mapConstIterator &operator=(mapConstIterator const &cpy)
            {
                if (cpy._end == true)
                    _ptr = new node(*(cpy._ptr));
                else
                    _ptr = cpy._ptr;
                _end = cpy._end;
                _root = cpy._root;
                return (*this);
            }
			// ++/-- operations in binary tree
			//https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
			mapConstIterator operator ++()
			{
                ptr tmp;
                tmp = _ptr;

                if (_root->rightmost(_root) == tmp)
                {
                    ptr bot = new node();
					bot->set_root(_ptr);
					_ptr = bot;
                    _end = true;
                    return (*this);
                }
				else if (_ptr->get_right())
                {
					_ptr = _ptr->leftmost(_ptr->get_right());
                    _end = false;
                    return (*this);
                }
				else if (_end == false)
				{
					ptr p = _ptr->get_root();
					while (p && _ptr == p->get_right())
					{
						_ptr = p;
						p = p->get_root();
					}
					_ptr = p;
				}
				return (*this);
			}
			mapConstIterator operator --()
			{
                if (_end == true)
                {
                    ptr tmp = _ptr;
                    _ptr = _ptr->get_root();
                    _end = false;
                    delete tmp;
                    return (*this);
                }
				if (_ptr->get_left())
				{
					_ptr = _ptr->get_left();
					while (_ptr->get_right())
						_ptr = _ptr->get_right();
				}
				else
					_ptr = _ptr->get_root();
				return (*this);
			}

			mapConstIterator operator++(int)
			{
				mapConstIterator before = *this;
				++(*this);
				return (before);
			}

			mapConstIterator operator--(int)
			{
				mapConstIterator before = *this;
				--(*this);
				return (before);
			}

			constReference operator*() const
			{
				return (_ptr->get_pair());
			}

			pointer operator->() const
			{
				return (&(_ptr->get_pair()));
			}

			bool operator==(mapConstIterator const &cmp)
			{
				if (_end == true && cmp._end == true)
					return (true);
				return (_ptr->get_key() == cmp._ptr->get_key());
			}

            bool operator!=(mapConstIterator const &cmp)
			{
				return (!(*this == cmp));
			}

			mapConstIterator leftmost()
			{
				while (_ptr->get_left() != NULL)
                    _ptr = _ptr->get_left();
				return (*this);
			}

			mapConstIterator rightmost()
			{
				while (_ptr->get_right() != NULL)
                    _ptr = _ptr->get_right();
				return (*this);
			}

            static const bool InputIter = true;
	};
    template <typename Tkey, typename Tvalue >
    class   mapRevIterator
    {
        public:
            typedef treeNode<Tkey, Tvalue>	        node;
            typedef node *					        ptr;
            typedef ft::pair<Tkey, Tvalue>	        value_type;
            typedef value_type &	                reference;
            typedef value_type const &              constReference;
            typedef value_type *	                pointer;
		protected :
			ptr										_ptr;
            ptr                                     _root;
            bool									_end;
        public :
            mapRevIterator(void){};
			mapRevIterator(ptr ptr) { _ptr = ptr; _end = false; _root = ptr;}
			mapRevIterator(const mapRevIterator &cpy)
            {
                if (cpy._end == true)
                    _ptr = new node(*(cpy._ptr));
                else
                    _ptr = cpy._ptr;
                _root = cpy._root;
                _end = cpy._end;
            };
			virtual ~mapRevIterator()
            {
                if (_end == true)
                    delete _ptr;
            };

			mapRevIterator &operator=(mapRevIterator const &cpy)
            {
                if (cpy._end == true)
                {
                    if (_end == true)
                       delete _ptr;
                    _ptr = new node(*(cpy._ptr));
                }
                else
                    _ptr = cpy._ptr;
                _end = cpy._end;
                _root = cpy._root;
                return (*this);
            }

            mapRevIterator operator++()
			{
				if (_end == true)
                {
                    ptr tmp = _ptr;
                    _ptr = _ptr->get_root();
                    _end = false;
                    delete tmp;
                    return (*this);
                }
				if (_ptr->get_left())
				{
					_ptr = _ptr->get_left();
					while (_ptr->get_right())
						_ptr = _ptr->get_right();
				}
				else
					_ptr = _ptr->get_root();
				return (*this);
			}

            mapRevIterator operator--()
            {
                ptr tmp;
                tmp = _ptr;

                if (_root->rightmost(_root) == tmp)
                {
                    ptr bot = new node();
					bot->set_root(_ptr);
					_ptr = bot;
                    _end = true;
                    return (*this);
                }
				else if (_ptr->get_right())
                {
					_ptr = _ptr->leftmost(_ptr->get_right());
                    _end = false;
                    return (*this);
                }
				else if (_end == false)
				{
					ptr p = _ptr->get_root();
					while (p && _ptr == p->get_right())
					{
						_ptr = p;
						p = p->get_root();
					}
					_ptr = p;
				}
				return (*this);
            }

            mapRevIterator operator++(int)
			{
				mapRevIterator before = *this;
				++(*this);
				return (before);
			}

			mapRevIterator operator--(int)
			{
				mapRevIterator before = *this;
				--(*this);
				return (before);
			}

            reference operator*()
			{
				return (_ptr->get_pair());
			}

			pointer operator->()
			{
				return (&(_ptr->get_pair()));
			}

			bool operator==(mapRevIterator const &cmp)
			{
				if (_end == true && cmp._end == true)
					return (true);
				return (_ptr->get_key() == cmp._ptr->get_key());
			}

            bool operator!=(mapRevIterator const &cmp)
			{
				return (!(*this == cmp));
			}

			mapRevIterator leftmost()
			{
				while (_ptr->get_left() != NULL)
                    _ptr = _ptr->get_left();
				return (*this);
			}

			mapRevIterator rightmost()
			{
				while (_ptr->get_right() != NULL)
                    _ptr = _ptr->get_right();
				return (*this);
			}

            static const bool InputIter = true;
    };

    template <typename Tkey, typename Tvalue >
    class   mapConstRevIterator 
    {
        public:
            typedef treeNode<Tkey, Tvalue>	        node;
            typedef node *					        ptr;
            typedef ft::pair<Tkey, Tvalue>	        value_type;
            typedef value_type &	                reference;
            typedef value_type const &              constReference;
            typedef value_type *	                pointer;
		protected :
			ptr										_ptr;
            ptr                                     _root;
            bool									_end;
        public :
            mapConstRevIterator(void){};
			mapConstRevIterator(ptr ptr) { _ptr = ptr; _end = false; _root = ptr;}
			mapConstRevIterator(const mapConstRevIterator &cpy)
            {
                if (cpy._end == true)
                    _ptr = new node(*(cpy._ptr));
                else
                    _ptr = cpy._ptr;
                _root = cpy._root;
                _end = cpy._end;
            };
			virtual ~mapConstRevIterator()
            {
                if (_end == true)
                    delete _ptr;
            };

			mapConstRevIterator &operator=(mapConstRevIterator const &cpy)
            {
                if (cpy._end == true)
                {
                    if (_end == true)
                       delete _ptr;
                    _ptr = new node(*(cpy._ptr));
                }
                else
                    _ptr = cpy._ptr;
                _end = cpy._end;
                _root = cpy._root;
                return (*this);
            }

            mapConstRevIterator operator++()
			{
				if (_end == true)
                {
                    ptr tmp = _ptr;
                    _ptr = _ptr->get_root();
                    _end = false;
                    delete tmp;
                    return (*this);
                }
				if (_ptr->get_left())
				{
					_ptr = _ptr->get_left();
					while (_ptr->get_right())
						_ptr = _ptr->get_right();
				}
				else
					_ptr = _ptr->get_root();
				return (*this);
			}

            mapConstRevIterator operator--()
            {
                ptr tmp;
                tmp = _ptr;

                if (_root->rightmost(_root) == tmp)
                {
                    ptr bot = new node();
					bot->set_root(_ptr);
					_ptr = bot;
                    _end = true;
                    return (*this);
                }
				else if (_ptr->get_right())
                {
					_ptr = _ptr->leftmost(_ptr->get_right());
                    _end = false;
                    return (*this);
                }
				else if (_end == false)
				{
					ptr p = _ptr->get_root();
					while (p && _ptr == p->get_right())
					{
						_ptr = p;
						p = p->get_root();
					}
					_ptr = p;
				}
				return (*this);
            }

            mapConstRevIterator operator++(int)
			{
				mapConstRevIterator before = *this;
				++(*this);
				return (before);
			}

			mapConstRevIterator operator--(int)
			{
				mapConstRevIterator before = *this;
				--(*this);
				return (before);
			}

            reference operator*()
			{
				return (_ptr->get_pair());
			}

			pointer operator->()
			{
				return (&(_ptr->get_pair()));
			}

			bool operator==(mapConstRevIterator const &cmp)
			{
				if (_end == true && cmp._end == true)
					return (true);
				return (_ptr->get_key() == cmp._ptr->get_key());
			}

            bool operator!=(mapConstRevIterator const &cmp)
			{
				return (!(*this == cmp));
			}

			mapConstRevIterator leftmost()
			{
				while (_ptr->get_left() != NULL)
                    _ptr = _ptr->get_left();
				return (*this);
			}

			mapConstRevIterator rightmost()
			{
				while (_ptr->get_right() != NULL)
                    _ptr = _ptr->get_right();
				return (*this);
			}

            static const bool InputIter = true;
    };
}
#endif

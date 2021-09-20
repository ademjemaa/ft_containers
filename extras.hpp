#ifndef EXTRAS_HPP
# define EXTRAS_HPP

#include <stdio.h>
# include <sstream>

namespace ft{

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
            pair& operator=( const pair& other )
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

            treeNode(void) : _pair(NULL),_root(NULL), _left(NULL), _right(NULL) {};
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

        private :
            pair		_pair;
            pointer		_root;
            pointer		_left;
            pointer		_right;
    };
}
#endif

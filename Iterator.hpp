/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:55:03 by adjemaa           #+#    #+#             */
/*   Updated: 2021/10/30 21:55:07 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include <limits>

namespace ft
{
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };
    
    //https://en.cppreference.com/w/cpp/iterator/iterator_tags
    
    template<typename Iter>
    struct iterator_traits
    {
        typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef random_access_iterator_tag iterator_category;
    };

    template<typename T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T*  pointer;
        typedef T&  reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<typename T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t  difference_type;
        typedef T  value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef random_access_iterator_tag iterator_category;
    
    };
    // If it is a random-access iterator, the function uses operator- to calculate this. 
    //Otherwise, the function uses the increase operator (operator++) repeatedly.
    //https://www.cplusplus.com/reference/iterator/distance/

    template<typename Iter>
    typename iterator_traits<Iter>::difference_type
    distance (Iter first, Iter last, input_iterator_tag)
    {
        typename iterator_traits<Iter>::difference_type total = 0;
        while (first != last)
        {
            total++;
            first++;
        }
        return (total);
    }
    template<typename RAIter>
    typename iterator_traits<RAIter>::difference_type
    distance (RAIter first, RAIter last, random_access_iterator_tag)
    {
        return last - first;
    }

    template<typename IT>
    typename iterator_traits<IT>::difference_type
    distance (IT first, IT last)
    {
        return distance(first, last, typename ft::iterator_traits<IT>::iterator_category());
    }

    //If it is a random-access iterator, the function uses just once operator+ or operator-.
    //Otherwise, the function uses repeatedly the increase or decrease operator (operator++ or operator--)
    //until n elements have been advanced.
    //https://www.cplusplus.com/reference/iterator/advance/

    template <typename RAIter, typename Distance>
    void advance (RAIter& it, Distance n, random_access_iterator_tag)
    {
        it += n;
    }

    template <typename ITer, typename Distance>
    void advance (ITer &it, Distance n, input_iterator_tag)
    {
        for (Distance i = 0; i < n; i++)
            it++;
    }

    template <typename IT, typename Distance>
	void advance(IT &it, Distance n)
	{
		return advance(it, n, typename iterator_traits<IT>::iterator_category());
	}

    //https://en.cppreference.com/w/cpp/iterator/reverse_iterator

    template <typename Iter>
    class reverse_iterator
    {
        public :
            Iter _base;
            typedef Iter iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category iterator_category;
            typedef typename iterator_traits<Iter>::value_type	value_type;
            typedef typename iterator_traits<Iter>::difference_type difference_type;
            typedef typename iterator_traits<Iter>::pointer pointer;
            typedef typename iterator_traits<Iter>::reference reference;

            reverse_iterator()
            {
            }

            reverse_iterator(Iter _base) : _base(_base)
            {
            }

            ~reverse_iterator()
            {
            }

            Iter base(void)
            {
                return (_base);
            }
            reverse_iterator(const reverse_iterator<Iter> &rev) : _base(rev._base)
            {
            }

            reverse_iterator<Iter> &operator=(const reverse_iterator<Iter> &rev)
            {
                _base = rev._base;
                return *this;
            }

            reverse_iterator<Iter> &operator++()
            {
                --_base;
                return *this;
            }

            reverse_iterator<Iter> operator++(int)
            {
                reverse_iterator temp = *this;
                ++(*this);
                return temp;
            }

            reverse_iterator<Iter> &operator--()
            {
                ++_base;
                return *this;
            }

            reverse_iterator<Iter> operator--(int)
            {
                reverse_iterator temp = *this;
                --(*this);
                return temp;
            }

            //http://www.cplusplus.com/reference/iterator/reverse_iterator/operator*/
            //read internal behavior in reference

            reference operator*()
            {
                return (*_base);
            }

            //http://www.cplusplus.com/reference/iterator/reverse_iterator/operator-%3E/

            pointer operator->()
            {
                return &(operator*());
            }

            //http://www.cplusplus.com/reference/iterator/reverse_iterator/operator+/

            reverse_iterator operator+ (difference_type n)
            {
                return (reverse_iterator(_base - n));
            }

            reverse_iterator& operator+= (difference_type n)
            {
                _base -= n;
                return (*this);
            }

            reverse_iterator operator- (difference_type n)
            {
                return (reverse_iterator(_base + n));
            }

            reverse_iterator& operator-= (difference_type n)
            {
                _base += n;
                return (*this);
            }

            reference operator[] (difference_type n)
            {
                return (*(*this + n));
            }   
    };

    //https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_cmp
    //comparisons

    template <typename Iterator1, typename Iterator2>
    bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs._base == rhs._base);
    }

    template <typename Iterator1, typename Iterator2>
    bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs._base != rhs._base);
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs._base > rhs._base);
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs._base >= rhs._base);
    }

    template <typename Iterator1, typename Iterator2>
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs._base < rhs._base);
    }

    template <typename Iterator1, typename Iterator2>
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs)
    {
        return (lhs._base <= rhs._base);
    }

    template<typename Iter >
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it)
    {
        return (reverse_iterator<Iter>(it._base - n));
    }

    template <typename Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,
               const reverse_iterator<Iterator>& rhs)
    {
        return (rhs._base - lhs._base);
    }

}

#endif

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

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
        typedef  Iter difference_type;
		typedef  Iter value_type;
		typedef  Iter pointer;
		typedef  Iter reference;
		typedef  Iter iterator_category;
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
        return distance(first, last, typename std::iterator_traits<IT>::iterator_category());
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
		return advance(it, n, typename IteratorTraits<IT>::iterator_category());
	}

    //https://en.cppreference.com/w/cpp/iterator/reverse_iterator

    template <typename Iter>
    class reverse_iterator
    {
        private :
            Iter base;
        public :
            typedef Iter iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category iterator_category;
            typedef typename iterator_traits<Iter>::value_type	value_type;
            typedef typename iterator_traits<Iter>::difference_type difference_type;
            typedef typename iterator_traits<Iter>::pointer pointer;
            typedef typename iterator_traits<Iter>::reference reference;

            reverse_iterator()
            {
            }

        

    };
}

#endif
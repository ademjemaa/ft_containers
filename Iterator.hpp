#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };
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
    //
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


}

#endif
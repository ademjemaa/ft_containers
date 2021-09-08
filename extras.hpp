#ifndef EXTRAS_HPP
# define EXTRAS_HPP

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
}
#endif
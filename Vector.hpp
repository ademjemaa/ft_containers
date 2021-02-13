#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{
    template <typename T>
    class VectorIterator
    {
        public :
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef size_t  size_type;
            
    };
}

#endif
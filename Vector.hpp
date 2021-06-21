#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stdio.h>

namespace ft
{
    template <typename T>
    class VectorIterator
    {
        public :
        //keyword typedef is a type definition where's in "typedef X Y;" X defines Y so Y = X in syntax
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef size_t  size_type;
        private :
            typedef VectorIterator<T> It;
            pointer p;
            VectorIterator(pointer e) : p(e){}
        public :
            VectorIterator() : p(NULL) {}
            VectorIterator(const It &elem) : p(elem.p) {}
            ~VectorIterator() {}
            It &operator=(const It &elem)
            {
                p = elem.p;
                return *this;
            }
            It &operator++()
            {
                ++p;
                return *this;
            }
            It operator++(int)
            {
                It it = *this;
                ++p;
                return it;
            }
            reference operator*() const
            {
                return *p;
            }
            pointer operator->() const
		    {
		    	return p;
		    }
            It &operator--()
            {
                --p;
                return *this;
            }
            It operator--(int)
            {
                It it = *this;
                --p;
                return it;
            }
            It &operator+=(size_type diff)
            {
                p += diff;
                return *this;
            }
            It &operator-=(size_type diff)
            {
                p -= diff;
                return *this;
            }
            reference operator[](difference_type diff) const
            {
                return *(*this + diff);
            }
            //the "friend" keyword gives access to protected and private members of the class they appear in
            //three functions and the class vector would need access to vectoriterator protected attributes
            template <typename _T>
            friend bool operator==(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template <typename _T>
            friend bool operator<(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template <typename _T>
            friend ptrdiff_t operator-(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template <typename _T>
            friend class Vector;
    };
    template <typename T>
	bool operator<(const VectorIterator<T> &one, const VectorIterator<T> &two)
	{
		return one.p < two.p;
	}
    template <typename T>
	bool operator>(const VectorIterator<T> &one, const VectorIterator<T> &two)
	{
		return !(one < two);
	}
    template <typename T>
	bool operator==(const VectorIterator<T> &one, const VectorIterator<T> &two)
    {
        if (!(one < two) && !(two < one))
            return (true);
        return (false);
    }
    template <typename T>
	bool operator==(const VectorIterator<T> &one, const VectorIterator<T> &two)
    {
        return !(one == two);
    }
	template <typename T>
	bool operator<=(const VectorIterator<T> &one, const VectorIterator<T> &two)
	{
		return !(one > two);
	}
	template <typename T>
	bool operator>=(const VectorIterator<T> &one, const VectorIterator<T> &two)
	{
		return !(one < two);
	}
    //https://www.cplusplus.com/reference/iterator/move_iterator/operator_plus-free/
    //https://en.cppreference.com/w/cpp/iterator/move_iterator/operator_arith
    template <typename T>
    VectorIterator<T> operator-(const VectorIterator<T> &it, size_t diff)
    {
        VectorIterator<T> tmp = it;
        return it -= diff
    }
    template <typename T>
    VectorIterator<T> operator-(size_t diff, const VectorIterator<T> &it)
    {
        return it -= diff
    }
	template <typename T>
	VectorIterator<T> operator+(const VectorIterator<T> &it, size_t diff)
	{
		VectorIterator<T> tmp = ite;
		return tmp += diff;
	}
    template <typename T>
	VectorIterator<T> operator+(size_t diff, const VectorIterator<T> &it)
	{
		return tmp += diff;
	}
    //https://www.cplusplus.com/reference/vector/vector/
    template <typename T>
    class Vector
    {
        public :
            typedef T value_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T &reference;
            typedef const T *const_pointer;
            typedef const T &const_reference;
            typedef VectorIterator<T> iterator;
            typedef VectorIterator<const T> const_iterator;
            typedef reverse_iterator<iterator> reverse_iterator;
            typedef reverse_iterator<const iterator> const_reverse_iterator;
        private :
            pointer array;
            size_type length;
            size_type capacity;
        public :
            //Constructs an empty container, with no elements.
            Vector() : array(NULL), length(0), capacity(0) {}
            //Constructs a container with n elements. Each element is a copy of val.
            Vector(size_type n, const value_type& val = value_type()) : array(NULL), length(0), capacity(0)
            {
                insert(begin(), n, val);
            }
            template <class InputIterator>
            Vector (InputIterator first, InputIterator last) : array(NULL), length(0), capacity(0)
            {
                insert(begin(), first, last);
            }
            Vector (const vector& x) : array(NULL), length(0), capacity(0)
            {
                insert(begin(), x.begin(), x.end());
            }
            ~Vector()
            {
                std::allocator<T> all;
                for (int i = 0, i < length, i++)
                    all.destroy(&array[i]);
                all.deallocate(array, capacity);
            }
            Vector &operator=(const vector& x)
		    {
                erase(x.begin(), x.end());
                insert(begin(), x.begin(), x.end());
                return *this;
		    }
            iterator begin()
            {
                return array;
            }
            const_iterator begin() const
            {
                return array;
            }
            iterator end()
            {
                return array + length;
            }
            const_iterator end() const
            {
                return array + length;
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator<VectorIterator<T>>(end());
            }
            const_reverse_iterator rbegin()
            {
                return reverse_iterator<VectorIterator<T>>(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator<VectorIterator<T>>(begin());
            }
            const_reverse_iterator rend()
            {
                return reverse_iterator<VectorIterator<T>>(begin());
            }
            size_type size() const
            {
                return length;
            }
            size_type max_size() const
            {
                return (std::numeric_limits<difference_type>::max() / sizeof(T));
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (length > n)
                    erase(begin() + n, end());
                else
                    insert(end(), n - length, val);
            }
            size_type capacity() const
            {
                return capacity;
            }
            bool empty() const
            {
                if (length == 0)
                    return (true);
                return (false);
            }
            
    };
}

#endif
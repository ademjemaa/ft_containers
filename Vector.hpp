#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stdio.h>
#include <memory>
#include "Iterator.hpp"

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
	bool operator!=(const VectorIterator<T> &one, const VectorIterator<T> &two)
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
        return it -= diff;
    }
    template <typename T>
    VectorIterator<T> operator-(size_t diff, const VectorIterator<T> &it)
    {
        return it -= diff;
    }
	template <typename T>
	VectorIterator<T> operator+(const VectorIterator<T> &it, size_t diff)
	{
		VectorIterator<T> tmp = it;
		return tmp += diff;
	}
    template <typename T>
	VectorIterator<T> operator+(size_t diff, const VectorIterator<T> &it)
	{
        VectorIterator<T> tmp = it;
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
            typedef ft::reverse_iterator<T> reverse_iterator;
            typedef ft::reverse_iterator<const T> const_reverse_iterator;
        private :
            pointer array;
            size_type length;
            size_type cap;
        public :
            //Constructs an empty container, with no elements.
            Vector() : array(NULL), length(0), cap(0) {}
            //Constructs a container with n elements. Each element is a copy of val.
            Vector(size_type n, const value_type& val = value_type()) : array(NULL), length(0), cap(0)
            {
                insert(begin(), n, val);
            }
            template <class InputIterator>
            Vector (InputIterator first, InputIterator last) : array(NULL), length(0), cap(0)
            {
                insert(begin(), first, last);
            }
            Vector (const Vector& x) : array(NULL), length(0), cap(0)
            {
                insert(begin(), x.begin(), x.end());
            }
            ~Vector()
            {
                std::allocator<value_type> all;
                for (int i = 0; i < length; i++)
                    all.destroy(&array[i]);
                all.deallocate(array, cap);
            }
            Vector &operator=(const Vector& x)
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
                return reverse_iterator<VectorIterator<T> >(end());
            }
            const_reverse_iterator rbegin() const
            {
                return reverse_iterator<VectorIterator<T> >(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator<VectorIterator<T> >(begin());
            }
            const_reverse_iterator rend() const
            {
                return reverse_iterator<VectorIterator<T> >(begin());
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
                return cap;
            }
            bool empty() const
            {
                if (length == 0)
                    return (true);
                return (false);
            }
            //reserve will allocate memory based on cap, if n is smaller or zero then no need to reallocate
            //otherwise allocate new array with new size, cpy all elements, destroy old array and change cap and pointer
            void reserve (size_type n)
            {
                if (n <= cap || cap == 0)
                    return ;
                std::allocator<T> all;
                pointer copy = all.allocate(n) ;
                for (int i = 0; i < length; i++)
                {
                    all.construct(&copy[i], array[i]);
                    all.destory(&array[i]);
                }
                all.deallocate(array, cap);
                array = copy;
                cap = n;
            }
            reference operator[] (size_type n)
            {
                return (array[n]);
            }
            const_reference operator[] (size_type n) const
            {
                return (array[n]);
            }
            reference at (size_type n)
            {
                if (n >= size())
                    throw std::out_of_range("out of range\n");
                return (array[n]);
            }
            const_reference at (size_type n) const
            {
                if (n >= size())
                    throw std::out_of_range("out of range\n");
                return (array[n]);
            }
            reference front()
            {
                return (array[0]);
            }
            const_reference front() const
            {
                return (array[0]);
            }
            reference back()
            {
                return (array[length - 1]);
            }
            const_reference back() const
            {
                return (array[length - 1]);
            }
            void assign (size_type n, const value_type& val)
            {
                reserve(n);
                insert(begin(), n, val);
            }
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {
                reserve(last - first);
                insert(begin(), first, last);
            }
            void push_back (const value_type& val)
            {
                insert(end(), val);
            }
            void pop_back()
            {
                erase(end() - 1);
            }
            iterator insert (iterator position, const value_type& val)
            {
                insert(position, 1, val);
                return (position);
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(position, 1, *first);
                    position++;
                    ++first;
                }
                
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                if (!n)
                    return;
                reserve(length + n);
                std::allocator<T> all;
                for (size_type i = length - 1; i >= position - array; i--)
                {
                    all.construct(&array[i + n], array[i]);
                    all.destroy(&array[i]);
                }
                for (size_type i = position - array; i < position - array + n; i++)
                    all.construct(&array[i],val);
                length = length + n;
            }
            iterator erase (iterator position)
            {
                erase(position, position + 1);
            }
            iterator erase (iterator first, iterator last)
            {
                std::allocator<T> all;
                if (first <= last)
                    return ;
                for (size_type i = first - array; i < array + last; i++)
                    all.destory(&array[i]);
                insert(first, last, end());
            }
            void swap (Vector& x)
            {
                std::swap(array, x.array);
                std::swap(length, x.length);
                std::swap(cap, x.cap);
            }
            void clear()
            {
                erase(begin(), end());
            }
    };
    //http://www.cplusplus.com/reference/vector/vector/operators/
    //compares vectors including their content and size
    template <typename T>
    bool operator==(const Vector<T> &lhs, const Vector<T> &rhs)
    {
        size_t i = 0;
        size_t j = 0;
        if (lhs.size() != rhs.size())
            return (false);
        while (i < lhs.size() && j < rhs.size() && lhs[i] == rhs[j])
        {
            i++;
            j++;
        }
        return (lhs[i] == rhs[j]);
    }
    template <typename T>
    bool operator!=(const Vector<T> &lhs, const Vector<T> &rhs)
    {
        return (!(lhs == rhs));
    }
    template <typename T>
    bool operator<(const Vector<T> &lhs, const Vector<T> &rhs)
    {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <typename T>
    bool operator>(const Vector<T> &lhs, const Vector<T> &rhs)
    {
        return (rhs < lhs);
    }
    template <typename T>
    bool operator<=(const Vector<T> &lhs, const Vector<T> &rhs)
    {
        return (!(rhs < lhs));
    }
    template <typename T>
    bool operator>=(const Vector<T> &lhs, const Vector<T> &rhs)
    {
        return (!(lhs < rhs));
    }
    template <typename T>
    void swap (Vector<T>& x, Vector<T>& y)
    {
        x.swap(y);
    }
}
#endif
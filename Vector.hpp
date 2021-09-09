#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stdio.h>
# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
#include "Iterator.hpp"
#include "extras.hpp"

namespace ft
{
    template <typename T, class Allocator>
	class Vector;
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
        public :
            VectorIterator(pointer e) : p(e){}
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
            
            //declaring inputIter as a valid member of vectoriterator
            //enable_if : https://en.cppreference.com/w/cpp/types/enable_if
            static const bool InputIter = true;

            //the "friend" keyword gives access to protected and private members of the class they appear in
            //three functions and the class vector would need access to vectoriterator protected attributes
            template <typename _T>
            friend bool operator==(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template <typename _T>
            friend bool operator<(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template <typename _T>
            friend ptrdiff_t operator-(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template <typename _T>
            friend ptrdiff_t operator+(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs);

            template<typename _T, class Allocator>
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
		return ((one == two) || (one < two));
	}
	template <typename T>
	bool operator>=(const VectorIterator<T> &one, const VectorIterator<T> &two)
	{
		return ((one == two) || (one > two));
	}
    //https://www.cplusplus.com/reference/iterator/move_iterator/operator_plus-free/
    //https://en.cppreference.com/w/cpp/iterator/move_iterator/operator_arith
    template <typename T>
    VectorIterator<T> operator-(VectorIterator<T> it, size_t diff)
    {
        VectorIterator<T> tmp = it;
        return it -= diff;
    }
    template <typename T>
    VectorIterator<T> operator-(size_t diff, VectorIterator<T> it)
    {
        return it -= diff;
    }
    template <typename _T>
    ptrdiff_t operator-(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs)
    {
        return lhs.p - rhs.p;
    }
	template <typename T>
	VectorIterator<T> operator+(VectorIterator<T> it, size_t diff)
	{
		VectorIterator<T> tmp = it;
		return tmp += diff;
	}
    template <typename T>
	VectorIterator<T> operator+(size_t diff,VectorIterator<T> it)
	{
        VectorIterator<T> tmp = it;
		return tmp += diff;
	}
    template <typename _T>
    ptrdiff_t operator+(const VectorIterator<_T> &lhs, const VectorIterator<_T> &rhs)
    {
        return lhs.p - rhs.p;
    }
    //https://www.cplusplus.com/reference/vector/vector/
    template <typename T, class Allocator = std::allocator<T> >
    class Vector
    {
        public :
            typedef Allocator allocator_type;
            typedef T value_type;
            typedef size_t size_type;
            typedef ptrdiff_t difference_type;
            typedef T *pointer;
            typedef T &reference;
            typedef const T *const_pointer;
            typedef const T &const_reference;
            typedef VectorIterator<T> iterator;
            typedef VectorIterator<const T> const_iterator;
            typedef reverse_iterator<iterator> rev;
            typedef reverse_iterator<const iterator> const_rev;
        private :
            Allocator all;
            pointer array;
            size_type length;
            size_type cap;
        public :
            //Constructs an empty container, with no elements.
            Vector(const allocator_type& alloc = allocator_type()) : all(alloc), array(NULL), length(0), cap(0) {}
            //Constructs a container with n elements. Each element is a copy of val.
            Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
            all(alloc), array(NULL), length(0), cap(0)
            {
                this->reserve(n);
		        for (size_type i = 0; i < n; i++)
			        all.construct(array + i, val);
                length = n;
            }
            template <typename InputIterator>
            Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<InputIterator::InputIter, InputIterator>::type = NULL) : all(alloc), array(NULL), length(0), cap(0)
            {
                insert(begin(), first, last);
            }
            Vector (const Vector& x) : array(NULL), length(0), cap(0)
            {
                insert(begin(), x.begin(), x.end());
            }
            ~Vector()
            {
                for (size_type i = 0; i < length; i++)
                    all.destroy(&array[i]);
                all.deallocate(array, cap);
            }
            Vector &operator=(const Vector& x)
		    {
                clear();
                insert(begin(), x.begin(), x.end());
                return *this;
		    }
            iterator begin()
            {
                return array;
            }
            const_iterator begin() const
            {
                return (array);
            }
            iterator end()
            {
                return (array + length);
            }
            const_iterator end() const
            {
                return array + length;
            }
            rev rbegin()
            {
                return reverse_iterator<VectorIterator<T> >(end());
            }
            const_rev rbegin() const
            {
                return reverse_iterator<VectorIterator<T> >(end());
            }
            rev rend()
            {
                return reverse_iterator<VectorIterator<T> >(begin());
            }
            const_rev rend() const
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
                if (n <= cap)
                    return ;
                pointer copy = all.allocate(n);
                for (size_type i = 0; i < length; i++)
                    all.construct(&copy[i], array[i]);
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
            void assign (const size_type n, const value_type val)
            {
                clear();
                insert(begin(), n, val);
            }
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last,
            typename ft::enable_if<InputIterator::InputIter, InputIterator>::type = NULL)
            {
                clear();
                insert(begin(), first, last);
            }
            void push_back (const value_type& val)
            {
                if (capacity() == length)
                    reserve(capacity() + 1);
                all.construct(array + length, val);
                length++;
            }
            void pop_back()
            {
                if (length > 0)
                {
                    all.destroy(array + (length - 1));
                    length--;
                }
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                size_type index = position.p - array;
                
                if (!n)
                    return;
                reserve(length + n);
                for (size_type i = length - 1; i > index && length != 0; i--)
                {
                    all.construct(&array[i + n], array[i]);
                    all.destroy(&array[i]);
                }
                for (size_type i = index; i < index + n; i++)
                {
                    
                    all.construct(&array[i], val);
                }
                length = length + n;
            }
            iterator insert (iterator position, const value_type& val)
            {
		        difference_type		pos = position - this->begin();
                size_type           len = length + 1;


                Vector		temp(position, this->end());
                Vector      tmp(this->begin(), position);

                clear();
                reserve(len);
                for (iterator it = tmp.begin(); it != tmp.end(); it++)
                    this->push_back(*it);

                this->push_back(val);

                for (iterator it = temp.begin(); it != temp.end(); it++)
                    this->push_back(*it);

                return (this->begin() + pos);
            }
            template <typename InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<InputIterator::InputIter, InputIterator>::type = NULL)
            {
                size_type index = position.p - array;
                size_type count = last - first;
                if (!count)
                    return;
                reserve(length + count); // reserve after calculating the index!
                // (otherwhise iterator `pos` is invalidated)

                for (ptrdiff_t i = length - 1; i >= (ptrdiff_t)index; i--)
                {
                    // move elements count times to the right
                    all.construct(&array[i + count], array[i]); // copy constructor
                    all.destroy(&array[i]);					// call destructor
                }

                for (InputIterator ite = first; ite != last; ++ite)
                    all.construct(&array[index++], *ite); // copy constructor

                length += count;
                
            }
            iterator erase (iterator position)
            {
				Vector rest(position + 1, end());

				for (size_type i = 0; i < rest.size(); i++)
					pop_back();
				pop_back();
				for (size_type i = 0; i < rest.size(); i++)
					push_back(rest[i]);
				return (position);

            }
            iterator erase (iterator first, iterator last)
            {
                iterator tmp(first);
				while (tmp != last)
				{
					erase(first);
					tmp++;
				}
                return (first);
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
    template <typename T, class Allocator>
    bool operator==(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs)
    {
        typename ft::Vector<T>::const_iterator it_left = lhs.begin();
        typename ft::Vector<T>::const_iterator it_right = rhs.begin();

        if (lhs.size() != rhs.size())
            return (false);
        for (;(it_left != lhs.end() && it_right != rhs.end() && *it_left == *it_right);
            it_left++, it_right++);
        return (it_left == lhs.end() && it_right == rhs.end());
    }
    template <typename T, class Allocator>
    bool operator!=(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs)
    {
        return (!(lhs == rhs));
    }
    template <typename T, class Allocator>
    bool operator<(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <typename T, class Allocator>
    bool operator>(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs)
    {
        return (rhs < lhs);
    }
    template <typename T, class Allocator>
    bool operator<=(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs)
    {
        return (!(rhs < lhs));
    }
    template <typename T, class Allocator>
    bool operator>=(const Vector<T, Allocator> &lhs, const Vector<T, Allocator> &rhs)
    {
        return (!(lhs < rhs));
    }
    template <typename T, class Allocator>
    void swap (Vector<T, Allocator>& x, Vector<T, Allocator>& y)
    {
        x.swap(y);
    }
    template <class T>
    std::ostream& operator <<(std::ostream& str, ft::Vector<T>& vec) 
    {
        if (vec.empty())
            return (str);
        str << "[";
        for (typename Vector<T>::iterator it = vec.begin(); it + 1 != vec.end(); ++it)
            str << *it << "; ";
        str << vec[vec.size() - 1] << "]";
        return str;
    }

}
#endif
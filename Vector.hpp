#ifndef VECTOR_HPP
#define VECTOR_HPP

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
}

#endif
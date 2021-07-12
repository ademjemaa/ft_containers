#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft{
    template <typename T, typename Container = Vector<T> > class Stack
    //https://www.cplusplus.com/reference/stack/stack/
    {
        public :
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        private :
            container_type ctnr;
        public :
            Stack(const container_type& ctnr = container_type()) : ctnr(ctnr){}
            ~Stack(){};
            Stack(const Stack<T, Container> &st) : ctnr(st.ctnr) {}
            Stack<T, Container> &operator=(const Stack<T, Container> &st)
            {
                ctnr = st.ctnr;
                return *this;
            }
            bool empty() const
            {
                return (ctnr.empty());
            }
            size_type size() const
            {
                return (ctnr.size());
            }
            value_type  &top()
            {
                return (ctnr.back());
            }
            void push (const value_type& val)
            {
                ctnr.push_back(val);
            }
            void pop()
            {
                ctnr.pop_back();
            }
            template<T, Container >
            friend bool operator==(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );

            template<T, Container >
            friend bool operator<(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs );
    };
    //https://en.cppreference.com/w/cpp/container/stack/operator_cmp
    template<typename T, typename Container >
    bool operator==(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
    {
        return (lhs.ctnr == rhs.ctnr);
    }

    template<typename T, typename Container >
    bool operator!=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
    {
        return !(lhs == rhs);
    }

    template<typename T, typename Container >
    bool operator<(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
    {
        return (lhs.ctnr < rhs.ctnr);
    }

    template<typename T, typename Container >
    bool operator<=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
    {
        return !(lhs > rhs);
    }

    template<typename T, typename Container >
    bool operator>(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
    {
        return (rhs < lhs);
    }

    template<typename T, typename Container >
    bool operator>=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs )
    {
        return !(lhs < rhs);
    }
}
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:55:19 by adjemaa           #+#    #+#             */
/*   Updated: 2021/11/15 17:25:38 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{
    template <typename T, typename Container = vector<T> > class stack
    //https://www.cplusplus.com/reference/stack/stack/
    {
        public :
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        protected :
            container_type  c;
        public :
            stack(const container_type& ctnr = container_type()) : c(ctnr){}
            ~stack(){};
            stack(const stack<T, Container> &st) : c(st.c) {}
            stack<T, Container> &operator=(const stack<T, Container> &st)
            {
                c = st.ctnr;
                return *this;
            }
            bool empty() const
            {
                return (c.empty());
            }
            size_type size() const
            {
                return (c.size());
            }
            value_type  &top()
            {
                return (c.back());
            }
            void push (const value_type& val)
            {
                c.push_back(val);
            }
            void pop()
            {
                c.pop_back();
            }
            template<typename T1 ,typename Container1>
            friend bool operator==(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );

            template<typename T1,typename Container1>
            friend bool operator<(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
    };
    //https://en.cppreference.com/w/cpp/container/stack/operator_cmp
    template<typename T, typename Container >
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c == rhs.c);
    }

    template<typename T, typename Container >
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return !(lhs == rhs);
    }

    template<typename T, typename Container >
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c < rhs.c);
    }

    template<typename T, typename Container >
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return !(lhs > rhs);
    }

    template<typename T, typename Container >
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (rhs < lhs);
    }

    template<typename T, typename Container >
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return !(lhs < rhs);
    }
}
#endif

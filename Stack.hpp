/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:55:19 by adjemaa           #+#    #+#             */
/*   Updated: 2021/10/30 21:58:54 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "Vector.hpp"

namespace ft{
    template <typename T, typename Container = vector<T> > class stack
    //https://www.cplusplus.com/reference/stack/stack/
    {
        public :
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        private :
            container_type ctnr;
        public :
            stack(const container_type& ctnr = container_type()) : ctnr(ctnr){}
            ~stack(){};
            stack(const stack<T, Container> &st) : ctnr(st.ctnr) {}
            stack<T, Container> &operator=(const stack<T, Container> &st)
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
            template<typename T1 ,typename Container1>
            friend bool operator==(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );

            template<typename T1,typename Container1>
            friend bool operator<(const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
    };
    //https://en.cppreference.com/w/cpp/container/stack/operator_cmp
    template<typename T, typename Container >
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.ctnr == rhs.ctnr);
    }

    template<typename T, typename Container >
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return !(lhs == rhs);
    }

    template<typename T, typename Container >
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.ctnr < rhs.ctnr);
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

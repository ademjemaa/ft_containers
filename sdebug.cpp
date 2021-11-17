/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdebug.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:55:29 by adjemaa           #+#    #+#             */
/*   Updated: 2021/11/15 17:08:03 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>
#include <iostream>
#include <vector>

void	stack_functions_test(void)
{

	ft::stack<int>	stack_one;
	ft::stack<int>	stack_two;

	stack_one.push(10);
	stack_one.push(11);
	stack_one.push(12);
	stack_one.push(122);
	stack_one.push(123);
	stack_one.push(1233);
	stack_one.push(1234);
	stack_one.push(12344);

	stack_two.push(10);
	stack_two.push(11);
	stack_two.push(12);
	stack_two.push(122);
	stack_two.push(123);
	stack_two.push(1233);
	stack_two.push(1234);
	stack_two.push(12344);
	stack_two.push(12345);

	std::cout << "stack_one size == " << stack_one.size() << std::endl;
	std::cout << "stack_two size == " << stack_two.size() << std::endl;
	std::cout << "stack content : (showing top then poping until stack.empty() == true" << std::endl;
	while (stack_one.empty() == false)
	{
		std::cout << stack_one.top() << std::endl;
		stack_one.pop();
	}
	std::cout << "stack_one size after popping all elements : " << stack_one.size() << std::endl;
}

void	stack_operators_test(void)
{
	ft::stack<int>	stack_one;
	ft::stack<int>	stack_two;

	stack_one.push(10);
	stack_one.push(11);
	stack_one.push(12);
	stack_one.push(122);
	stack_one.push(123);
	stack_one.push(1233);
	stack_one.push(1234);
	stack_one.push(12344);

	stack_two.push(10);
	stack_two.push(11);
	stack_two.push(12);
	stack_two.push(122);
	stack_two.push(123);
	stack_two.push(1233);
	stack_two.push(1234);
	stack_two.push(12344);
	stack_two.push(12345);

	std::cout << "stack_one == stack_two : " << std::boolalpha << (stack_one == stack_two) << std::endl;
	std::cout << "stack_one != stack_two : " << std::boolalpha << (stack_one != stack_two) << std::endl;
	std::cout << "stack_one > stack_two : " << std::boolalpha << (stack_one > stack_two) << std::endl;
	std::cout << "stack_one < stack_two : " << std::boolalpha << (stack_one < stack_two) << std::endl;
	std::cout << "stack_one >= stack_two : " << std::boolalpha << (stack_one >= stack_two) << std::endl;
	std::cout << "stack_one <= stack_two : " << std::boolalpha << (stack_one <= stack_two) << std::endl;
	std::cout << "popping last element of stack two " << std::endl;
	stack_two.pop();
	std::cout << "stack_one == stack_two : " << std::boolalpha << (stack_one == stack_two) << std::endl;
	std::cout << "stack_one != stack_two : " << std::boolalpha << (stack_one != stack_two) << std::endl;
	std::cout << "stack_one > stack_two : " << std::boolalpha << (stack_one > stack_two) << std::endl;
	std::cout << "stack_one < stack_two : " << std::boolalpha << (stack_one < stack_two) << std::endl;
	std::cout << "stack_one >= stack_two : " << std::boolalpha << (stack_one >= stack_two) << std::endl;
	std::cout << "stack_one <= stack_two : " << std::boolalpha << (stack_one <= stack_two) << std::endl;
	std::cout << "printing and popping all elements of both stacks " << std::endl;
	std::cout << "stack_one : " << std::endl;
	while (stack_one.empty() == false)
	{
		std::cout << stack_one.top() << std::endl;
		stack_one.pop();
	}
	std::cout << "stack_two : " << std::endl;
	while (stack_two.empty() == false)
	{
		std::cout << stack_two.top() << std::endl;
		stack_two.pop();
	}
	std::cout << "stack_one == stack_two : " << std::boolalpha << (stack_one == stack_two) << std::endl;
	std::cout << "stack_one != stack_two : " << std::boolalpha << (stack_one != stack_two) << std::endl;
	std::cout << "stack_one > stack_two : " << std::boolalpha << (stack_one > stack_two) << std::endl;
	std::cout << "stack_one < stack_two : " << std::boolalpha << (stack_one < stack_two) << std::endl;
	std::cout << "stack_one >= stack_two : " << std::boolalpha << (stack_one >= stack_two) << std::endl;
	std::cout << "stack_one <= stack_two : " << std::boolalpha << (stack_one <= stack_two) << std::endl;
	std::cout << "stack_one empty : " << std::boolalpha << stack_one.empty() << std::endl;
	std::cout << "stack_two empty : " << std::boolalpha << stack_two.empty() << std::endl;
}

void  stack_debug(void)
{
    stack_functions_test();
	stack_operators_test();
}

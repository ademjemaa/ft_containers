/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjemaa <adjemaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:55:21 by adjemaa           #+#    #+#             */
/*   Updated: 2021/11/15 17:08:29 by adjemaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include "vector.hpp"

void	vec_insert_test(void)
{
	ft::vector<int> vec(40);

	for (int i = 0; i < 40; i++)
	{
		if (i % 8)
			vec[i] = i * 2;
		else
			vec[i] = i - 2;
	}
	for (int i = 0; i < 40; i ++)
		std::cout << vec[i] << std::endl;
	ft::vector<int>	second;
	second.assign(++(vec.begin()), (vec.end() - 15));
	std::cout << "second vector after assign" << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	second.assign(15, 22);
	std::cout << "second after 15 22s were assigned to it" << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	second.pop_back();
	second.pop_back();
	second.pop_back();
	second.pop_back();
	second.push_back(33);
	second.push_back(43);
	std::cout << "max_size of second : " << second.max_size() << std::endl;
	std::cout << "second after popping 4 times and pushing 33/43" << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	second.insert(second.end()--, 55);
	second.insert(second.end() - 2, 3, 6);
	second.insert(second.begin(), vec.begin() + 5, vec.begin() + 10);
	std::cout << "second after second.insert(second.end()--, 55), second.insert(second.end() - 2, 3, 6), second.insert(second.begin(), vec.begin() + 5, vec.begin() + 10)" << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "size of vector so far : " << second.size() << std::endl;
	second.swap(vec);
	std::cout << "size and content of second vector after swapping with vec : " << second.size() << std::endl;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "size and content of vec vector after swapping with second : " << vec.size() << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "vec but with a rev iterator " << std::endl;
	for (ft::vector<int>::rev it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << std::endl;
	vec.resize(10, 15);
	std::cout << "vec after resizing to 10,15 " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "vec capacity : " << vec.capacity() <<std::endl;
	std::cout << "vec front : " << vec.front() << " vec back : " << vec.back() << std::endl;
	vec.erase(vec.begin() + 1);
	vec.erase(vec.begin() + 1, vec.end() - 5);
	std::cout << "vec after erassing " << std::endl;
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
}

void	vector_debug(void)
{
	vec_insert_test();

}

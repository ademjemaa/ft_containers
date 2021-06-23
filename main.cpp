/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skybt <skybt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:31:12 by skybt             #+#    #+#             */
/*   Updated: 2020/08/08 12:37:33 by skybt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

int main()
{
	std::cout << "azebi\n";
	ft::Vector<int> vec;
	vec.push_back(0);
	vec.push_back(60);
	vec.push_back(550);
	vec.push_back(40);
	vec.push_back(440);
	vec.push_back(30);
	vec.push_back(10);
	vec.push_back(1002);
	vec.push_back(20);
	std::cout << vec.size();
	ft::Vector<int> vec2(vec);
	std::cout << vec2.size();
}
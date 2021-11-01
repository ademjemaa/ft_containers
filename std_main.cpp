#include <stack>
#include <vector>
#include <map>

#include <iostream>
#include <string>
#include <deque>


#include <stdlib.h>

void	brackets_test(void)
{
	std::map<int, int>	int_map1;
	std::map<std::string, std::string>	string_map1;
	std::cout << "  ####\nSTD TEST\n  ####" << std::endl;
	int_map1[1] = 0;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[1] = 10;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[2] = 20;
	std::cout << "int_map[1] = " << int_map1[2] << std::endl;
	std::cout << "int_map size = " << int_map1.size() << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	string_map1["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map1["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	std::cout << "\n\n\n" << std::endl;
}

void	insert_test(void)
{
	std::map<int, int>	int_map1;
	std::map<int, int> swap_map1;
	std::map<int, int>	cpy_int_map1;
	std::map<std::string, std::string>	string_map1;
	std::cout << "  ####\nSTD TEST\n  ####" << std::endl;
	int_map1[1] = 0;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[1] = 10;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[2] = 20;
	std::cout << "int_map[2] = " << int_map1[2] << std::endl;
	std::cout << "int_map size = " << int_map1.size() << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	string_map1["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map1["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	int_map1.insert(std::make_pair(12, 15));
	std::cout << "int_map[12] = " << int_map1[12] << std::endl;
	cpy_int_map1.insert(int_map1.begin(), int_map1.end());
	std::cout << "cpy_int_map :" << std::endl;
	for (std::map<int, int>::iterator it = cpy_int_map1.begin(); it != cpy_int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	cpy_int_map1.insert(++(cpy_int_map1.begin()), std::make_pair(30, 20));
	std::cout << "cpy_int_map after insertion by it:" << std::endl;
	for (std::map<int, int>::iterator it = cpy_int_map1.begin(); it != cpy_int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	swap_map1 = cpy_int_map1;
	std::cout << "swap_map1 before: " << std::endl;
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "swap_map1 after: " << std::endl;
	int_map1.swap(swap_map1);
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "int_map1 after: " << std::endl;
	for (std::map<int, int>::iterator it = int_map1.begin(); it != int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}

void	erase_test(void)
{
	std::map<int, int>	int_map1;
	std::map<int, int>	cpy_int_map1;
	std::map<int, int> swap_map1;
	std::map<std::string, std::string>	string_map1;
	std::cout << "  ####\nSTD TEST\n  ####" << std::endl;
	int_map1[1] = 0;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[1] = 10;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[2] = 20;
	std::cout << "int_map[2] = " << int_map1[2] << std::endl;
	std::cout << "int_map size = " << int_map1.size() << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	string_map1["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map1["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	int_map1.insert(std::make_pair(12, 15));
	std::cout << "int_map[12] = " << int_map1[12] << std::endl;
	cpy_int_map1.insert(int_map1.begin(), int_map1.end());
	std::cout << "cpy_int_map :" << std::endl;
	for (std::map<int, int>::iterator it = cpy_int_map1.begin(); it != cpy_int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	cpy_int_map1.insert(++(cpy_int_map1.begin()), std::make_pair(30, 20));
	std::cout << "cpy_int_map after insertion by it:" << std::endl;
	for (std::map<int, int>::iterator it = cpy_int_map1.begin(); it != cpy_int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	swap_map1 = cpy_int_map1;
	std::cout << "swap_map1 before: " << std::endl;
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "swap_map1 after: " << std::endl;
	int_map1.swap(swap_map1);
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "int_map1 after: " << std::endl;
	for (std::map<int, int>::iterator it = int_map1.begin(); it != int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	swap_map1.erase(12);
	int_map1.erase(++(int_map1.begin()), --(int_map1.end()));
	std::cout << "swap_map after erasing key 12: " << std::endl;
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	swap_map1.erase(swap_map1.begin());
	std::cout << "swap_map after erasing begin: " << std::endl;
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "int_map after erasing begin + 1 until end - 1: " << std::endl;
	for (std::map<int, int>::iterator it = int_map1.begin(); it != int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	cpy_int_map1.clear();
	std::cout << "cpy_int_map1 size after clear : " << cpy_int_map1.size() <<std::endl;
}

void	find_test(void)
{
	std::map<int, int>	int_map1;
	std::map<int, int> swap_map1;
	std::map<int, int>	cpy_int_map1;
	std::map<std::string, std::string>	string_map1;
	std::cout << "  ####\nSTD TEST\n  ####" << std::endl;
	std::cout << "wut" << std::endl;
	int_map1[1] = 0;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[1] = 10;
	std::cout << "int_map[1] = " << int_map1[1] << std::endl;
	int_map1[2] = 20;
	std::cout << "int_map[2] = " << int_map1[2] << std::endl;
	std::cout << "int_map size = " << int_map1.size() << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	string_map1["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map1["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map1.size() << std::endl;
	int_map1.insert(std::make_pair(12, 15));
	std::cout << "int_map[12] = " << int_map1[12] << std::endl;
	cpy_int_map1.insert(int_map1.begin(), int_map1.end());
	std::cout << "cpy_int_map :" << std::endl;
	for (std::map<int, int>::iterator it = cpy_int_map1.begin(); it != cpy_int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	cpy_int_map1.insert(++(cpy_int_map1.begin()), std::make_pair(30, 20));
	std::cout << "cpy_int_map after insertion by it:" << std::endl;
	for (std::map<int, int>::iterator it = cpy_int_map1.begin(); it != cpy_int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	swap_map1 = cpy_int_map1;
	std::cout << "swap_map1 before: " << std::endl;
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "swap_map1 after: " << std::endl;
	int_map1.swap(swap_map1);
	for (std::map<int, int>::iterator it = swap_map1.begin(); it != swap_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "int_map1 after: " << std::endl;
	for (std::map<int, int>::iterator it = int_map1.begin(); it != int_map1.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
	std::cout << "inserting pair elements into int_map" << std::endl;
	for (int i = 0; i < 20; i++)
		if (i % 2 == 0)
			int_map1[i] = i + 1;
	for (int i = 0; i < 20; i++)
		if (int_map1.find(i) != int_map1.end())
			std::cout << "key " << i << " found, second : " << int_map1[i] << std::endl;
	std::map<int, int>::iterator it1;
	it1 = cpy_int_map1.lower_bound(2);
	std::cout << "lower bound of key 2 " << it1->second << std::endl;
	it1 = cpy_int_map1.upper_bound(2);
	std::cout << "upper bound of key 2 " << it1->second << std::endl;
	std::cout << "count, which is a completely useless function due to the fact that this container does not allow duplicates, thus making the return of this function either 1 or 0 (found or not found) : ";
	std::cout << cpy_int_map1.count(2) << std::endl;
	std::cout << ((cpy_int_map1.equal_range(2)).first)->first << std::endl;
}

void	compare_test(void)
{
	std::cout << "  ####\nSTD TEST\n  ####" << std::endl;
	std::map<int, int> firstmap1;
	for (int i = 0; i < 35; i++)
		if (i % 3 == 0)
			firstmap1[i] = i + 5;
	std::map<int, int>::iterator it1;
	std::pair<int, int> pr1;
	it1 = firstmap1.end();
	it1--;
	pr1 = *it1;
	it1 = firstmap1.begin();
	std::cout << "value comparing (which uses std::less) compares two pairs with said function through keys" << std::endl;
	while (firstmap1.value_comp()(*it1, pr1))
	{
		std::cout << it1->first << " <= " << pr1.first << std::endl;
		it1++;
	}
	it1 = firstmap1.begin();
	std::cout << "key comparing (which uses std::less) compares two keys with said function" << std::endl;
	while (firstmap1.key_comp()(it1->first, pr1.first))
	{
		std::cout << it1->first << " <= " << pr1.first << std::endl;
		it1++;
	}
}

void	std_map_debug(void)
{
	brackets_test();
	insert_test();
	erase_test();
	find_test();
	compare_test();
}

void	std_vector_debug(void)
{
	std::vector<int> vec(40);

	for (int i = 0; i < 40; i++)
	{
		if (i % 8)
			vec[i] = i * 2;
		else
			vec[i] = i - 2;
	}
	for (int i = 0; i < 40; i ++)
		std::cout << vec[i] << std::endl;
	std::vector<int>	second;
	second.assign(++(vec.begin()), (vec.end() - 15));
	std::cout << "second vector after assign" << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	second.assign(15, 22);
	std::cout << "second after 15 22s were assigned to it" << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	second.pop_back();
	second.pop_back();
	second.pop_back();
	second.pop_back();
	second.push_back(33);
	second.push_back(43);
	std::cout << "second after popping 4 times and pushing 33/43" << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	second.insert(second.end()--, 55);
	second.insert(second.end() - 2, 3, 6);
	second.insert(second.begin(), vec.begin() + 5, vec.begin() + 10);
	std::cout << "second after second.insert(second.end()--, 55), second.insert(second.end() - 2, 3, 6), second.insert(second.begin(), vec.begin() + 5, vec.begin() + 10)" << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "size of vector so far : " << second.size() << std::endl;
	second.swap(vec);
	std::cout << "size and content of second vector after swapping with vec : " << second.size() << std::endl;
	for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "size and content of vec vector after swapping with second : " << vec.size() << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "vec but with a rev iterator " << std::endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << *it << std::endl;
	vec.resize(10, 15);
	std::cout << "vec after resizing to 10,15 " << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "vec capacity : " << vec.capacity() <<std::endl;
	std::cout << "vec front : " << vec.front() << " vec back : " << vec.back() << std::endl;
	vec.erase(vec.begin() + 1);
	vec.erase(vec.begin() + 1, vec.end() - 5);
	std::cout << "vec after erassing " << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
}

void	stack_functions_test(void)
{

	std::stack<int>	stack_one;
	std::stack<int>	stack_two;

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
	std::stack<int>	stack_one;
	std::stack<int>	stack_two;

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

void	std_stack_debug(void)
{
	stack_functions_test();
	stack_operators_test();
}

int main(void)
{
	std_map_debug();
	std_vector_debug();
	std_stack_debug();
}

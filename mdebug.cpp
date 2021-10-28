#include "extras.hpp"
#include <iostream>
#include <iterator>
#include <map>
#include "Map.hpp"

void	brackets_test(void)
{
	std::cout << "#####\nBRACKETS TEST\n#####" << std::endl;
	ft::map<int, int>	int_map;
	ft::map<std::string, std::string>	string_map;

	int_map[1] = 0;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[1] = 10;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[2] = 20;
	std::cout << "int_map[1] = " << int_map[2] << std::endl;
	std::cout << "int_map size = " << int_map.size() << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	string_map["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
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
	std::cout << "#####\nINSERT TEST\n#####" << std::endl;
	ft::map<int, int>	int_map;
	ft::map<int, int>	cpy_int_map;
	ft::map<int, int> swap_map;
	ft::map<std::string, std::string>	string_map;

	int_map[1] = 0;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[1] = 10;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[2] = 20;
	std::cout << "int_map[2] = " << int_map[2] << std::endl;
	std::cout << "int_map size = " << int_map.size() << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	string_map["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	int_map.insert(ft::make_pair(12, 15));
	std::cout << "int_map[12] = " << int_map[12] << std::endl;
	cpy_int_map.insert(int_map.begin(), int_map.end());
	std::cout << "cpy_int_map :" << std::endl;
	for (ft::map<int, int>::iterator it = cpy_int_map.begin(); it != cpy_int_map.end(); it++)
		std::cout << *it << std::endl;
	cpy_int_map.insert(++(cpy_int_map.begin()), ft::make_pair(30, 20));
	std::cout << "cpy_int_map after insertion by it:" << std::endl;
	for (ft::map<int, int>::iterator it = cpy_int_map.begin(); it != cpy_int_map.end(); it++)
		std::cout << *it << std::endl;
	swap_map = cpy_int_map;
	std::cout << "swap_map before: " << std::endl;
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "swap_map after: " << std::endl;
	int_map.swap(swap_map);
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "int_map after: " << std::endl;
	for (ft::map<int, int>::iterator it = int_map.begin(); it != int_map.end(); it++)
		std::cout << *it << std::endl;


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
	std::cout << "#####\nERASE TEST\n#####" << std::endl;
	ft::map<int, int>	int_map;
	ft::map<int, int>	cpy_int_map;
	ft::map<int, int> swap_map;
	ft::map<std::string, std::string>	string_map;

	int_map[1] = 0;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[1] = 10;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[2] = 20;
	std::cout << "int_map[2] = " << int_map[2] << std::endl;
	std::cout << "int_map size = " << int_map.size() << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	string_map["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	int_map.insert(ft::make_pair(12, 15));
	std::cout << "int_map[12] = " << int_map[12] << std::endl;
	cpy_int_map.insert(int_map.begin(), int_map.end());
	std::cout << "cpy_int_map :" << std::endl;
	for (ft::map<int, int>::iterator it = cpy_int_map.begin(); it != cpy_int_map.end(); it++)
		std::cout << *it << std::endl;
	cpy_int_map.insert(++(cpy_int_map.begin()), ft::make_pair(30, 20));
	std::cout << "cpy_int_map after insertion by it:" << std::endl;
	for (ft::map<int, int>::iterator it = cpy_int_map.begin(); it != cpy_int_map.end(); it++)
		std::cout << *it << std::endl;
	swap_map = cpy_int_map;
	std::cout << "swap_map before: " << std::endl;
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "swap_map after: " << std::endl;
	int_map.swap(swap_map);
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "int_map after: " << std::endl;
	for (ft::map<int, int>::iterator it = int_map.begin(); it != int_map.end(); it++)
		std::cout << *it << std::endl;
	swap_map.erase(12);
	int_map.erase(++(int_map.begin()), --(int_map.end()));
	std::cout << "swap_map after erasing key 12: " << std::endl;
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	swap_map.erase(swap_map.begin());
	std::cout << "swap_map after erasing begin: " << std::endl;
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "int_map after erasing begin + 1 until end - 1: " << std::endl;
	for (ft::map<int, int>::iterator it = int_map.begin(); it != int_map.end(); it++)
		std::cout << *it << std::endl;
	cpy_int_map.clear();
	std::cout << "cpy_int_map size after clear : " << cpy_int_map.size() <<std::endl;

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
	std::cout << "#####\nFIND TEST\n#####" << std::endl;
	ft::map<int, int>	int_map;
	ft::map<int, int>	cpy_int_map;
	ft::map<int, int> swap_map;
	ft::map<std::string, std::string>	string_map;

	int_map[1] = 0;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[1] = 10;
	std::cout << "int_map[1] = " << int_map[1] << std::endl;
	int_map[2] = 20;
	std::cout << "int_map[2] = " << int_map[2] << std::endl;
	std::cout << "int_map size = " << int_map.size() << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	string_map["NUMBAONE"] = "china";
	std::cout << "string_map[\"NUMBAONE\"] = " << string_map["NUMBAONE"] << std::endl;
	std::cout << "string_map size = " << string_map.size() << std::endl;
	int_map.insert(ft::make_pair(12, 15));
	std::cout << "int_map[12] = " << int_map[12] << std::endl;
	cpy_int_map.insert(int_map.begin(), int_map.end());
	std::cout << "cpy_int_map :" << std::endl;
	for (ft::map<int, int>::iterator it = cpy_int_map.begin(); it != cpy_int_map.end(); it++)
		std::cout << *it << std::endl;
	cpy_int_map.insert(++(cpy_int_map.begin()), ft::make_pair(30, 20));
	std::cout << "cpy_int_map after insertion by it:" << std::endl;
	for (ft::map<int, int>::iterator it = cpy_int_map.begin(); it != cpy_int_map.end(); it++)
		std::cout << *it << std::endl;
	swap_map = cpy_int_map;
	std::cout << "swap_map before: " << std::endl;
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "swap_map after: " << std::endl;
	int_map.swap(swap_map);
	for (ft::map<int, int>::iterator it = swap_map.begin(); it != swap_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "int_map after: " << std::endl;
	for (ft::map<int, int>::iterator it = int_map.begin(); it != int_map.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "inserting pair elements into int_map" << std::endl;
	for (int i = 0; i < 20; i++)
		if (i % 2 == 0)
			int_map[i] = i + 1;
	for (int i = 0; i < 20; i++)
		if (int_map.find(i) != int_map.end())
			std::cout << "key " << i << " found, second : " << int_map[i] << std::endl;
	ft::map<int, int>::iterator it;
	it = cpy_int_map.lower_bound(2);
	std::cout << "lower bound of key 2 " << *it << std::endl;
	it = cpy_int_map.upper_bound(2);
	std::cout << "upper bound of key 2 " << *it << std::endl;
	std::cout << "count, which is a completely useless function due to the fact that this container does not allow duplicates, thus making the return of this function either 1 or 0 (found or not found) : ";
	std::cout << cpy_int_map.count(2) << std::endl;
	std::cout << *((cpy_int_map.equal_range(2)).first) << std::endl;

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
	std::cout << "lower bound of key 2 " << *it << std::endl;
	it1 = cpy_int_map1.upper_bound(2);
	std::cout << "upper bound of key 2 " << *it << std::endl;
	std::cout << "count, which is a completely useless function due to the fact that this container does not allow duplicates, thus making the return of this function either 1 or 0 (found or not found) : ";
	std::cout << cpy_int_map1.count(2) << std::endl;
	std::cout << ((cpy_int_map1.equal_range(2)).first)->first << std::endl;
}

void	compare_test(void)
{
	std::cout << "#####\nCOMPARE TEST\n#####" << std::endl;
	ft::map<int, int> firstmap;
	for (int i = 0; i < 35; i++)
		if (i % 3 == 0)
			firstmap[i] = i + 5;
	ft::map<int, int>::iterator it;
	ft::pair<int, int> pr;
	it = firstmap.end();
	it--;
	pr = *it;
	it = firstmap.begin();
	std::cout << "value comparing (which uses ft::less) compares two pairs with said function through keys" << std::endl;
	while (firstmap.value_comp()(*it, pr))
	{
		std::cout << *it << " <= " << pr << std::endl;
		it++;
	}
	it = firstmap.begin();
	std::cout << "key comparing (which uses ft::less) compares two keys with said function" << std::endl;
	while (firstmap.key_comp()(it->first, pr.first))
	{
		std::cout << it->first << " <= " << pr.first << std::endl;
		it++;
	}
	
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

void map_debug(void)
{
	brackets_test();
	insert_test();
	erase_test();
	find_test();
	compare_test();
}

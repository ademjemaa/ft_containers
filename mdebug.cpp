#include "extras.hpp"
#include <iostream>
#include <iterator>
#include <map>
#include "Map.hpp"

void	brackets_test(void)
{
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
	//cpy_int_map.insert(++(cpy_int_map.begin()), ft::make_pair(30, 20));
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

	std::map<int, int>	int_map1;
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
}


int main(void)
{
	brackets_test();
	insert_test();
	while(1);/*
	ft::pair<int, std::string>	t1(ft::make_pair<int, std::string>(1, "string"));
	std::map<int, int> one;
	ft::map<int, int> three;
	ft::map<int, int>::iterator it;

	it = three.insert(NULL, ft::pair<int, int>(1, 55));
	std::cout << three.size() << std::endl;
	three.insert(ft::pair<int, int>(5, 999));
	three[2] = 66;std::cout << three.size() << std::endl;
	three[3] = 77;std::cout << three.size() << std::endl;

	std::cout << three[1] << std::endl;
	std::cout << three[2] << std::endl;
	std::cout << three[3] << std::endl;

	three[-1] = 50;std::cout << three.size() << std::endl;

	ft::map<int, int>::iterator rm;
		std::cout << *it << std::endl;
	rm = three.begin();
	for (it = three.begin(); it != three.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	it = three.end();
	it--;
	three.insert(it, ft::pair<int, int>(666,666));std::cout << three.size() << std::endl;
	for (it = three.begin(); it != three.end(); it++);
	--it;
	std::cout << "excuse me " << std::endl;
	three.insert(it, ft::pair<int, int>(33, 1337));
	std::cout << three.size() << std::endl;
	std::cout << "map three : " << std::endl;
	for (it = three.begin(); it != three.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	ft::map<int, int>	four;
	std::cout << three.size() << std::endl;
	ft::map<int, int>::iterator it2;
	std::cout << "map four :" << std::endl;
	four.insert(++(three.begin()), three.end());
	std::cout << four.size() << std::endl;
	for (it2 = four.begin(); it2 != four.end(); it2++)
	{
		std::cout << *it2 << std::endl;
	}
	std::cout << three.size() << std::endl;
	ft::map<int, int> trimo = three;
	std::cout << trimo.size()<< std::endl;
	three.erase(3);
	std::cout << three.size() << std::endl;

	std::cout << "key 3 deleted" << std::endl;
	one.insert(std::pair<int, int>(1, 40));
	one.insert(std::pair<int, int>(0, 50));
	one.insert(std::pair<int, int>(5, 55));
	one.insert(std::pair<int, int>(10, 60));
	one.insert(std::pair<int, int>(12, 55));

	three.erase(three.begin(), three.end());

	std::cout << three.size() << std::endl;

	ft::treeNode<int, int> tot(ft::make_pair<int, int>(1, 55));
	ft::treeNode<int, int> tot2(ft::make_pair<int, int>(5, 505));

	std::cout << tot.get_pair() << std::endl;
	tot.set_right(&tot2);
	if (ft::is_integral<bool>::value)
		std::cout << "value is true " << std::endl;
	std::cout << (tot.get_right())->get_pair() << std::endl;
	std::map<int, int>::iterator itr;
	std::cout << "lower bound of 4 " << *(four.lower_bound(4)) << std::endl;
	std::cout << "lower bound of 5 " << *(four.upper_bound(5)) << std::endl;
	for (itr = one.begin(); itr != one.end(); ++itr) {
        std::cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

	std::map<int, int>::iterator en;

	en = one.end();
	en--;
	std::cout << "first " << en->first << " second " << en->second << std::endl;
	std::cout << "last " << std::endl;
*/
}

#include "extras.hpp"
#include <iostream>
#include <iterator>
#include <map>
#include "Map.hpp"

int main()
{
	ft::pair<int, std::string>	t1(ft::make_pair<int, std::string>(1, "string"));
	std::map<int, int> one;

	one.insert(std::pair<int, int>(1, 40));
	one.insert(std::pair<int, int>(0, 50));
	one.insert(std::pair<int, int>(5, 55));
	one.insert(std::pair<int, int>(10, 60));
	one.insert(std::pair<int, int>(12, 55));
	ft::treeNode<int, int> tot(ft::make_pair<int, int>(1, 55));
	ft::treeNode<int, int> tot2(ft::make_pair<int, int>(5, 505));

	std::cout << tot.get_pair() << std::endl;
	tot.set_right(&tot2);
	std::cout << (tot.get_right())->get_pair() << std::endl;
	std::map<int, int>::iterator itr;

	for (itr = one.begin(); itr != one.end(); ++itr) {
        std::cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

	std::map<int, int>::iterator en;

	en = one.end();
	en--;
	std::cout << "first " << en->first << " second " << en->second << std::endl;
}

#include "extras.hpp"
#include <iostream>
#include <iterator>
#include <map>
#include "Map.hpp"

int main()
{
	ft::pair<int, std::string>	t1(ft::make_pair<int, std::string>(1, "string"));
	std::map<int, int> one;
	ft::map<int, int> three;
	ft::map<int, int>::iterator it;


	it = three.insert(NULL, ft::pair<int, int>(1, 55));

	three.insert(ft::pair<int, int>(5, 999));

	three[2] = 66;
	three[3] = 77;

	std::cout << three[1] << std::endl;
	std::cout << three[2] << std::endl;
	std::cout << three[3] << std::endl;

	three[-1] = 50;


	std::cout << *it << std::endl;
	three.insert(it, ft::pair<int, int>(666,666));
	for (it = three.begin(); it != three.end(); it++);
	--it;
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

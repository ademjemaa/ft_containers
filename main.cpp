#include "Vector.hpp"
#include <vector>

void	map_debug(void);

void	test_assign(void)
{
	ft::Vector<int> vec;

	vec.assign(6, 2);
	ft::Vector<int> vec2;
	std::cout << vec << std::endl;

	
	vec2.push_back(33);
	std::cout << vec2 << std::endl;
	vec2.assign(vec.begin(), vec.end());
	std::cout << vec2 << std::endl;
	vec2.pop_back();
	std::cout << vec2 << std::endl;
	vec2.resize(4, 4);
	std::cout << vec2 << std::endl;
	vec2.clear();
	std::cout << vec2 << std::endl;
}

int main()
{
	test_assign();
	map_debug();
}
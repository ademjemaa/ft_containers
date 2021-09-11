#include "extras.hpp"
#include <iostream>

int main()
{
	ft::pair<int, std::string>	t1(ft::make_pair<int, std::string>(1, "string"));

	std::cout << t1 << std::endl;
}

#include "Vector.hpp"
#include <vector>
#include "Stack.hpp"
#include "Vector.hpp"
#include "Map.hpp"
#include <map>

#include <iostream>
#include <string>
#include <deque>


#include <stdlib.h>

#define MAX_RAM 4200000
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))


void	map_debug(void);
void	vector_debug(void);
void	stack_debug(void);

void	test_assign(void)
{
	ft::vector<int> vec;

	vec.assign(6, 2);
	ft::vector<int> vec2;
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


int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	ft::map<int, int> map_int;
	for (int i = 0; i < COUNT; i++)
	{	
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	/*MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}*/
	std::cout << std::endl;
	test_assign();
	map_debug();
	vector_debug();
	//stack_debug();
	return (0);
}
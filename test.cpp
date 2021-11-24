#include <map>
#include "map.hpp"
#define TESTED  std

int main()
{
    TESTED::map<int, int> mp;
    mp.insert(TESTED::make_pair(50,20));
    mp.insert(TESTED::make_pair(33,33));
    mp.insert(TESTED::make_pair(66, 66));
    TESTED::map<int, int>::reverse_iterator it3 = mp.rend();
    TESTED::map<int, int>::iterator it(it3);
    std::cout << it3->first;
    it3++;
    std::cout << mp.rend()->first << std::endl;
    std::cout << it3->first;
}
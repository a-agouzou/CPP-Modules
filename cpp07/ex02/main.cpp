#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> tab(5);
    std::cout << "-------Before:-------" << std::endl;
    for(int i=0; i < 5;i++)
    {
        std::cout << tab[i] << std::endl;
        tab[i] = 1337;
    }
    std::cout << "-------After:-------" << std::endl;
    for(int i=0; i < 5;i++)
        std::cout << tab[i] << std::endl;
    try
    {
        std::cout << std::endl;
        tab[0] = 42;
        std::cout << "index 0: " << tab[0] << std::endl;
        tab[-2] = 42;
        std::cout << "index 0: " << tab[0] << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
   
}
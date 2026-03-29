#include "Classe_razionali.hpp"
#include <iostream>

int main()
{
    rational<int> a(7,1);
    rational<int> b(3,-28);

    rational<int> c = a - b;

    std::cout <<"Primo razionale "<< a << "\n";
    std::cout <<"Secondo razionale "<< b << "\n";
    std::cout << "Calcolo "<< c << "\n";

    return 0;
}
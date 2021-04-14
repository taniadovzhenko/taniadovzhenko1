/*
g++ calculations.cpp -o calculations
*/

#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

double f(double x, unsigned n)
{
    double y = 0;
    for (unsigned i = 1; i <= n; i++)
        y += pow(i * x, i);

    return y;
}

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3)
    {
        std::cerr << "Please, provide an x-value." << std::endl;
        return 1;
    }

    double x = boost::lexical_cast<double>(argv[1]);
    unsigned n = 10;

    if (argc == 3)
        n = boost::lexical_cast<unsigned>(argv[2]);

    double y = f(x, n);
    std::cout << boost::format{"f(x=%1%, n=%2%) = %3%"} % x % n % y << std::endl;

    return 0;
}
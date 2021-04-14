/*
g++ chainFraction.cpp -o chainFraction
*/

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

double f(unsigned n, unsigned i = 0)
{
    if (i == n)
        return 1 / (4 * i + 2);
    else
        return 1 / f(n, ++i) + (4 * i + 2);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Provide n" << std::endl;
        exit(1);
    }

    auto n = boost::lexical_cast<unsigned>(argv[1]);
    double y = f(n);

    std::cout << boost::format{"f(n=%1%) = %2%"} % n % y << std::endl;

    return 0;
}
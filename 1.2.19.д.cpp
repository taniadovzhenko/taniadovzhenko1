/*
g++ sequence.cpp -o sequence 
*/

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

double f(double x, unsigned k)
{
    if (k == 0)
        return 1;
    else
        return f(x, k - 1) * (x * x) / ((2 * k - 1) * 2 * k);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Invalid amount of arguments (required 2)" << std::endl;
        exit(1);
    }

    double x = boost::lexical_cast<double>(argv[1]);
    unsigned k = boost::lexical_cast<unsigned>(argv[2]);

    double y = f(x, k);
    std::cout << boost::format{"f(x=%1%, k=%2%) = %3%"} % x % k % y << std::endl;

    return 0;
}
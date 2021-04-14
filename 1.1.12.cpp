/*
0 ------------------------> +x
|
|
|
|
|
+y

g++ squaresIntersect.cpp -o squaresIntersect
*/

#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <boost/format.hpp>

typedef std::pair<double, double> vec2d_t;

struct Rectangle
{
    vec2d_t topLeft;
    vec2d_t bottomRight;

    vec2d_t sides() const
    {
        return {bottomRight.first - topLeft.first, bottomRight.second - topLeft.second};
    }
};

std::pair<vec2d_t, vec2d_t> intersection(const Rectangle &lhs, const Rectangle &rhs, bool *status = nullptr)
{
    vec2d_t topLeft = {std::max(lhs.topLeft.first, rhs.topLeft.first),
                       std::max(lhs.topLeft.second, rhs.topLeft.second)};
    vec2d_t bottomRight = {std::min(lhs.bottomRight.first, rhs.bottomRight.first),
                           std::min(lhs.bottomRight.second, rhs.bottomRight.second)};

    if (status)
        *status = (topLeft.first < bottomRight.first && topLeft.second < bottomRight.second);

    return {topLeft, bottomRight};
}

std::ostream &operator<<(std::ostream &os, vec2d_t &vec)
{
    os << boost::format{"{%1%, %2%}"} % vec.first % vec.second;
    return os;
}

static Rectangle
    _s1{{2, 6}, {6, 10}},
    _s2{{4, 7}, {12, 15}},
    _s3{{-3, -3}, {-2, -2}},
    _s4{{3, 7}, {4, 8}};
static std::map<std::string, Rectangle> corr = {
    {"s1", _s1}, {"s2", _s2}, {"s3", _s3}, {"s4", _s4}};

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Please, provide two rectangles (s1 to s4)!" << std::endl;
        exit(1);
    }

    Rectangle s1 = corr[argv[1]], s2 = corr[argv[2]];
    std::cout << (std::string)argv[1] << ": " << s1.topLeft << " " << s1.bottomRight << std::endl;
    std::cout << (std::string)argv[2] << ": " << s2.topLeft << " " << s2.bottomRight << std::endl;

    bool ok;
    auto intersectionCoords = intersection(s1, s2, &ok);

    if (ok)
        std::cout << "Topleft: " << intersectionCoords.first << std::endl
                  << "Bottomright: " << intersectionCoords.second << std::endl;
    else
        std::cout << "No intersection found." << std::endl;

    return 0;
}
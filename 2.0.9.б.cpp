/*
g++ fullEvenCubes.cpp -o fullEvenCubes  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

bool is_perfect_cube(int n)
{
    int root = round(cbrt(n));
    return n == root * root * root;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (auto &el : arr)
        std::cin >> el;

    int count = 0;
    std::for_each(arr.begin(), arr.end(), [&count](int el) {
        count += (is_perfect_cube(el) && (el % 2 == 0));
    });

    std::cout << "Result: " << count << std::endl;

    return 0;
}
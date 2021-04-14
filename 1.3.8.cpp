/*
g++ binswap.cpp -o binswap    
*/

#include <iostream>
#include <bitset>

int main()
{
    unsigned long long M;
    std::cin >> M;

    std::bitset<64> Mb(M);
    std::cout << "Before: " << std::dec << M << " " << std::hex << M << " " << Mb << std::endl;

    unsigned i, j;
    std::cin >> i >> j;

    unsigned ith = (M >> i) & 1U, jth = (M >> j) & 1U;
    M ^= (-ith ^ M) & (1UL << j);
    M ^= (-jth ^ M) & (1UL << i);
    Mb = M;

    std::cout << " After: " << std::dec << M << " " << std::hex << M << " " << Mb << std::endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> readNumbers(const std::string &filename) {
    std::fstream file(filename, std::ios::in);
    if (!file.is_open()) std::exit(1);

    int n;
    std::vector<int> res;
    while (file >> n)
        res.push_back(n);

    file.close();

    return res;
}

void writeNumbers(const std::string &filename, const std::vector<int>::iterator begin,
                  const std::vector<int>::iterator end) {
    std::fstream file(filename, std::ios::out);
    if (!file.is_open()) std::exit(1);

    auto it = begin;
    while (it != end)
        file << *it++ << " ";

    file.close();
}

std::vector<int> getDivisors(int n) {
    std::vector<int> divisors;

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            divisors.push_back(i);

    return divisors;
}

int main() {
    auto numbers = readNumbers("F");
    auto end = std::remove_if(numbers.begin(), numbers.end(), [](int el) {
        std::cout << el << " => ";
        for (auto &div : getDivisors(el)) {
            std::cout << div << " ";
        }
        std::cout << std::endl;
        return getDivisors(el).size() != 3;
    });

    writeNumbers("G", numbers.begin(), end);

    return 0;
}

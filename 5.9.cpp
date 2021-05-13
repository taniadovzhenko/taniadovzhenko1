#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> readFile(const std::string &filename) {
    std::fstream file(filename, std::ios::in);
    if (!file.is_open()) std::exit(1);

    std::vector<std::string> res;
    std::string buff;
    while (std::getline(file, buff)) {
        res.push_back(buff);
    }

    file.close();
    return res;
}

void writeFile(const std::string &filename, const std::vector<std::string> &lines) {
    std::fstream file(filename, std::ios::out);
    if (!file.is_open()) std::exit(1);

    for (auto &line : lines) {
        file << line << std::endl;
    }

    file.close();
}

int main() {
    auto f1 = readFile("f1.txt");
    auto f2 = readFile("f2.txt");

    for (int i = 0; i < f1.size(); i++) {
        f1[i] += f2[i % f2.size()];
    }

    writeFile("f3.txt", f1);

    return 0;
}

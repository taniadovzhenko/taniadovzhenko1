#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

typedef std::pair<unsigned, unsigned> bound_t;

class Toy {


public:
    Toy(std::string type, double price, bound_t age)
            : type_(std::move(type)), price_(price), age_(std::move(age)) {}

public:
    const std::string &type() const {
        return type_;
    }

    double price() const {
        return price_;
    }

    const bound_t &age() const {
        return age_;
    }

private:
    std::string type_;
    double price_;
    bound_t age_;
};

std::vector<std::string> costLessThanFor5(const std::vector<Toy> &toys, double price) {
    std::vector<Toy> filtered;
    std::copy_if(toys.begin(), toys.end(), std::back_inserter(filtered), [&price](const Toy &t) {
       return t.age().first <= 5 && t.age().second >= 5 && t.price() <= price;
    });

    unsigned idx = 0;
    std::vector<std::string> res(filtered.size());
    std::generate(res.begin(), res.end(), [&filtered, idx]{ return filtered[idx].type(); });

    return res;
}

auto findConstructorWithPrice(const std::vector<Toy> &toys, double price) {
    return std::find_if(toys.begin(), toys.end(), [&price](const Toy &t) {
        return t.price() == price && t.age().first == 5 && t.age().second == 10;
    });
}

void log(const std::string& info) {
    std::fstream file("toys.log", std::ios::out | std::ios::binary);
    std::vector<std::ostream *> streams{&file, &std::cout};

    for (auto &stream_prt : streams) {
        *stream_prt << info << std::endl;
    }
}

int main() {
    auto toys = std::vector<Toy> {
            Toy("lego", 12.50, {5, 12}),
            Toy("constructor", 10.50, {5, 10}),
            Toy("doll", 122.0, {2, 8}),
            Toy("constructor", 3.50, {5, 10}),
    };

    std::stringstream ss;

    // A
    auto res1 = costLessThanFor5(toys, 12);
    for (auto &el : res1)
        ss << el << ", ";
    ss << std::endl;

    // B
    auto res2 = findConstructorWithPrice(toys, 10.50);
    if (res2 == std::end(toys)) {
        ss << "Could not find any appropriate constructor" << std::endl;
    }
    else {
        ss << (*res2).type() << " " << (*res2).price() << std::endl;
    }

    log(ss.str());

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string &s, const char delim) {
    std::vector<std::string> res;
    std::string buffer;

    for (auto &c : s) {
        if (c == delim) {
            res.push_back(buffer);
            buffer = "";
        } else buffer += c;
    }

    return res;
}

struct Date {
    int d, m, y;

    static Date fromString(const std::string &s) {
        // (dd/mm/yy)
        int d = std::stoi(s.substr(1, 2));
        int m = std::stoi(s.substr(4, 2));
        int y = std::stoi(s.substr(7, 2));

        return Date{d, m, y};
    }

    std::string toString() const {
        std::stringstream ss;
        ss << "(" << d << "/" << m << "/" << y<< ")";

        return ss.str();
    }

    bool operator<(const Date &other) const {
        return (this->y + 50) % 100 < (other.y + 50) % 100;
    }
};

std::vector<Date> readDates(const std::string &filename) {
    std::fstream file(filename, std::ios::in);
    if (!file.is_open()) std::exit(1);

    std::string content(
            (std::istreambuf_iterator<char>(file)),
            (std::istreambuf_iterator<char>())
    );

    unsigned idx = 0;
    auto dateStrings = split(content, ',');
    std::vector<Date> dates(dateStrings.size());
    std::generate(dates.begin(), dates.end(), [&idx,dateStrings]{ return Date::fromString(dateStrings[idx++]); });

    file.close();

    return dates;
}

void writeDates(const std::vector<Date> &dates, const std::string &filename) {
    std::fstream file(filename, std::ios::out);
    if (!file.is_open()) std::exit(1);

    for (auto &date : dates) {
        file << date.toString() << ",";
    }

    file.close();
}

int main() {
    auto dates = readDates("dates.txt");
    auto min = std::min_element(dates.begin(), dates.end());
    auto max = std::max_element(dates.begin(), dates.end());

    std::vector<Date> res = {*min, *max};
    writeDates(res, "dates_b.txt");

    return 0;
}
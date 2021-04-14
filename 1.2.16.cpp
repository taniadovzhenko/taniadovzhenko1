#include <iostream>
#include <climits>

static auto INF = ULLONG_MAX;
typedef unsigned long long ULLONG;

ULLONG streamMinimumIdx(ULLONG currMin = +INF, ULLONG currMinIdx = -1, ULLONG currIdx = -1)
{
    currIdx++;

    ULLONG n;
    std::cin >> n;

    if (!n)
        return currMinIdx;
    else
        return streamMinimumIdx(n < currMin ? n : currMin, n < currMin ? currIdx : currMinIdx, currIdx);
}

int main()
{
    std::cout << streamMinimumIdx() << std::endl;

    return 0;
}
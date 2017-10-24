#include <iostream>
#include <vector>

const ushort COUNT = 8;
std::vector<std::pair<ushort, ushort> > queens;

bool isTakes(const std::pair<ushort, ushort> & a, const std::pair<ushort, ushort> & b)
{
    return (((a.first + a.second) == (b.first + b.second)) || ((a.second == b.second) || (a.first == b.first)) || ((a.first - b.first) == (a.second - b.second)));
}

int main() {
    ushort a, b;
    for (ushort i = 0; i < COUNT; ++i)
        std::cin >> a >> b, queens.push_back(std::make_pair(a, b));

    for (ushort i = 0; i < COUNT; ++i)
        for (ushort j = i + 1; j < COUNT; ++j)
            if (isTakes(queens[i], queens[j]))
            {
                std::cout << "YES";
                return 0;
            }
    std::cout << "NO";
}

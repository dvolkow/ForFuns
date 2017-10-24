#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<uint, uint> puiui;
std::vector<puiui> list;

bool less(const puiui & a, const puiui & b)
{
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main() {
    uint n, a, b;
    std::cin >> n;
    for (uint i = 0; i < n; ++i)
        std::cin >> a >> b, list.push_back(std::make_pair(b, a));
    std::sort(list.begin(), list.end(), less);
    for (uint i = 0; i < n; ++i)
        std::cout << list[i].second << " " << list[i].first << "\n";
}

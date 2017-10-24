#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> pii;
std::vector<pii> list;

bool less(const pii & a, const pii & b)
{
    return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
}

int main() 
{
    int n, a, b;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a >> b, list.push_back(std::make_pair(b, a));
    std::sort(list.begin(), list.end(), less);
    for (int i = 0; i < n; ++i)
        std::cout << list[i].second << " " << list[i].first << "\n";
}

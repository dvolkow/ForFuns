#include <iostream>
#include <set>

std::set<uint> pairs;

int main()
{
    uint b_size, pair_max, current_pair, count = 0;
    std::cin >> b_size >> pair_max;
    for (uint i = 0; i < pair_max; ++i)
    {
        std::cin >> current_pair; 
        if (current_pair >= b_size)
            pairs.insert(current_pair);
    }

    uint prev = b_size;
    if (pairs.count(prev))
        ++count;

    for (auto i : pairs)
        if (i - prev > 2 || count == 0)
            ++count, prev = i;

    std::cout << count;
}


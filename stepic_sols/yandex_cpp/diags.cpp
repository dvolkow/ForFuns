#include <iostream>
#include <vector>

int main() {
    short n;
    short tmp, k;
    std::vector<std::vector<short> > v; 
    std::cin >> n;
    v.resize(n);
    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < n; ++j)
            std::cin >> tmp, v[i].push_back(tmp);
    std::cin >> k;
    for (short i = 0; i < n; ++i)
        for (short j = 0; j < n; ++j)
            if (i - j == k)
                std::cout << v[i][j] << " ";
}

#include <iostream>
#include <iomanip>

int main() {
    ushort n, m, count = 0;
    std::cin >> n >> m;
    for (ushort i = 0; i < n; ++i)
       for (ushort j = 0; j < m; ++j) 
           std::cout << std::setw(4) << ((i + j) % 2 == 0 ? ++count : 0) << (j == m - 1 ? "\n" : " ");
}

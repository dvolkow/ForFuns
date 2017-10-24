#include <iostream>
#include <iomanip>

int main() {
    ushort n, m, count = 0;
    std::cin >> n >> m;
    for (ushort i = 0; i < n; ++i)
    {
       if (i % 2 == 1)
           count += m + 1;
       for (ushort j = 0; j < m; ++j) 
           std::cout << std::setw(4) << (i % 2 == 0 ? ++count : --count) << (j == m - 1 ? "\n" : " ");
       if (i % 2 == 1)
           count += m - 1;
    }
}

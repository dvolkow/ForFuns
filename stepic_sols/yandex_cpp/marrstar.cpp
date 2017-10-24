#include <iostream>

int main() {
    ushort n;
    std::cin >> n;
    for (ushort i = 0; i < n; ++i) 
        for (ushort j = 0; j < n; ++j)
            std::cout << ((i == j || i == n/2 || j == n/2 || i == n - j - 1) ? "* " : ". ") << (j == n - 1 ? "\n" : "");
}

#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int> > arr;
    int tmp; 
    ushort n, m;
    // -- чтение
    std::cin >> n >> m;
    arr.resize(n);

    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < m; ++j)
            std::cin >> tmp, arr[i].push_back(tmp);
    // test
    for (ushort j = 0; j < m; ++j)
        for (ushort i = 0; i < n; ++i)
            std::cout << arr[i][j] << (i != n - 1 ? " " : "\n");
}

#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int> > arr;
    int tmp;
    ushort n, m, k, l;
    // -- чтение
    std::cin >> n >> m;
    arr.resize(n);

    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < m; ++j)
            std::cin >> tmp, arr[i].push_back(tmp);
    std::cin >> k >> l;
    // -- вывод
    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < m; ++j)
            std::cout << (j == k ? arr[i][l] : (j == l ? arr[i][k] : arr[i][j])) << (j == m - 1 ? "\n" : " ");
}

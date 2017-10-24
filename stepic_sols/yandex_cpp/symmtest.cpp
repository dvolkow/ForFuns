#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int> > arr;
    int tmp; bool is_symm = true;
    ushort n;
    // -- чтение
    std::cin >> n;
    arr.resize(n);

    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < n; ++j)
            std::cin >> tmp, arr[i].push_back(tmp);
    // test
    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < n; ++j)
            if (arr[i][j] != arr[j][i])
                is_symm = false;
    std::cout << (is_symm ? "YES" : "NO");
}

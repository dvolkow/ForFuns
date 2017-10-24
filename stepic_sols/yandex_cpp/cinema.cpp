#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<ushort> > arr;
    ushort n, m, tmp, counter = 0;
    // -- чтение
    std::cin >> n >> m;
    arr.resize(n);
    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < m; ++j)
            std::cin >> tmp, arr[i].push_back(tmp); 
    std::cin >> tmp;
    // -- определение
    for (ushort i = 0; i < n; ++i, counter = 0)
        for (ushort j = 0; j < m; ++j)
        {
            counter = (arr[i][j] == 0 ? counter + 1 : 0);  
            if (counter == tmp)
            {
                std::cout << i + 1;
                return 0;
            }
        }
    std::cout << "0";
}

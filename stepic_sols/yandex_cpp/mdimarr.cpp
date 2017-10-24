#include <iostream>
#include <climits>

int main() 
{
    ushort n, m, m_i, m_j;
    int max = -1 * INT_MAX, tmp;
    std::cin >> n >> m;
    for (ushort i = 0; i < n; ++i)
        for (ushort j = 0; j < m; ++j)
        {
            std::cin >> tmp;
            if (tmp > max)
                max = tmp, m_i = i, m_j = j;
        } 
    std::cout << m_i << " " << m_j;
}

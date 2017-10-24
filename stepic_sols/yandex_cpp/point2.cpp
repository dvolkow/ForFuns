#include <iostream>
#include <cmath>

bool IsPointInSquare(const double x, const double y)
{
    return std::fabs(x + y) <= 1 && std::fabs(x - y) <= 1;
}

int main() {
    double x, y;
    std::cin >> x >> y;
    std::cout << (IsPointInSquare(x, y) ? "YES" : "NO");

}

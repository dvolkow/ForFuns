#include <iostream>

bool IsPointInCircle(const double x, const double y, const double xc, const double yc, const double r)
{
    return (x - xc) * (x - xc) + (y - yc) * (y - yc) <= r * r; 
}

int main() {
    double x, y, xc, yc, r;
    std::cin >> x >> y >> xc >> yc >> r;
    std::cout << (IsPointInCircle(x, y, xc, yc, r) ? "YES" : "NO");
}

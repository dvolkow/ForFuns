#include <iostream>

double power(const double a, const ushort n)
{
    return n != 0 ? a * power(a, n - 1) : 1;
}

int main() {
    double a;
    short n;
    std::cin >> a >> n;
    std::cout << (n >= 0 ? power(a, n) : 1 / power(a, -n));
}

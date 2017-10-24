#include <iostream>
#include <vector>

std::vector<double> a;
short n;

int main() {
    double x;
    std::cin >> n, a.resize(n+1);
    std::cin >> x;
    for (short i = n; i >= 0; --i)
        std::cin >> a[i];
    double tmp = a[n];
    for (short i = n - 1; i >= 0; --i)
        tmp = tmp * x + a[i];

    std::cout << tmp;
}

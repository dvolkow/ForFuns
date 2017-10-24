#include <iostream>

double det(const double a11, const double a12, const double a21, const double a22)
{
	return a11 * a22 - a12 * a21;
}

int main()
{
	double a, b, c, d, e, f;
	std::cin >> a >> b >> c >> d >> e >> f;
	std::cout << det(b, e, d, f) / det(a, b, c, d) << " " << det(a, e, c, f) / det(a, b, c, d);
}

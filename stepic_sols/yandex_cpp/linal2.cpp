#include <iostream>
#include <cmath>

const double PREC = 1e-9;

double det(const double a11, const double a12, const double a21, const double a22)
{
	return a11 * a22 - a12 * a21;
}

int main()
{
	double a, b, c, d, e, f;
	std::cin >> a >> b >> c >> d >> e >> f;
	const double main_det = det(a, b, c, d);
	const double x_det = det(b, e, d, f);
	const double y_det = det(a, e, c, f);
	
	// -- единственно:
	if (std::fabs(main_det) > PREC)
	{
		std::cout << "2 " << - (x_det / main_det) << " " << y_det / main_det;
		return 0;
	}

	// -- нет решений:
	if (std::fabs(main_det) < PREC && (std::fabs(x_det) >= PREC || std::fabs(y_det) >= PREC 
									|| (std::fabs(e) >= PREC) || (std::fabs(f) >= PREC)))
	{
		std::cout << "0";
		return 0;
	}

	// -- любое число решение:
	if (std::fabs(a) < PREC && std::fabs(b) < PREC && std::fabs(c) < PREC 
		&& std::fabs(d) < PREC && std::fabs(e) < PREC && std::fabs(f) < PREC)
	{
		std::cout << "5";
		return 0;
	}

	// -- прямая
	if (std::fabs(main_det) < PREC && std::fabs(x_det) < PREC && std::fabs(y_det) < PREC)
	{
		if ((std::fabs(b) < PREC && std::fabs(d) < PREC) || std::fabs(b + d) < PREC)
		{
			std::cout << "3 " << e / a;
			return 0;
		}

		if ((std::fabs(a) < PREC && std::fabs(c) < PREC) || std::fabs(a + c) < PREC)
		{
			std::cout << "4 " << e / b;
			return 0;
		}

		std::cout << "1 " << -((a + c) / (b + d)) << " " << (e + f) / (b + d);
	}
}

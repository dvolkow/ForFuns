#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
  	double a, b, c;
  	std::cin >> a >> b >> c;
	
	// Линейное вырожденное?
	if (std::fabs(a) < 0.0000000001 && std::fabs(b) < 0.0000000001 && std::fabs(c) < 0.0000000001)
	{
		std::cout << "3 ";
		return 0;
	}

	// Линейное невырожденное?
	if (std::fabs(a) < 0.0000000001 && std::fabs(b) > 0.0000000001)
	{
		std::cout << "1 " << std::setprecision(11) << (-c) / b;
		return 0;
	}

	if (std::fabs(a) < 0.0000000001 && std::fabs(b) < 0.0000000001 && std::fabs(c) > 0.0000000001)
	{
		std::cout << "0";
		return 0;
	}
  
	// Квадратное:
  	double d = b * b - 4 * a * c;
  	if (std::fabs(d) < 0.0000000001)
      	std::cout << "1 " << std::setprecision(11) << (-b) / (2.0 * a);
  	else if (d > 0.000000000001)
  	{
      	if (a > 0)
       	   std::cout << "2 " << std::setprecision(11) << (-b - std::sqrt(d)) / (2.0 * a) << " " 
                << (-b + std::sqrt(d)) / (2.0 * a) ;   
      	else 
       	   std::cout << "2 " << std::setprecision(11) << (-b + std::sqrt(d)) / (2.0 * a) << " " 
                << (-b - std::sqrt(d)) / (2.0 * a) ; 
  	}
	else 
		std::cout << "0";
      
}

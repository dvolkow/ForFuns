/*
 * Даны целые числа 1≤n≤10181≤n≤1018 и 2≤m≤1052≤m≤105, необходимо найти остаток от деления nn-го числа Фибоначчи на mm.
 */

#include <iostream>
#include <vector>

typedef unsigned long long ull;
typedef std::pair<uint, uint> puiui;

int main()
{
	uint m; 
	std::vector<puiui> fibs = {std::make_pair(0, 0), std::make_pair(1,1)};
	ull n;
	std::cin >> n >> m;

	// -- маленькие n;
	if (n < 3)
	{
		std::cout << (n == 1 ? 0 : 1);
		return 0;
	}	

	uint prev = 0, cur = 1;
	for (uint i = 2; i < m; ++i)
	{
		prev = cur;
		uint tmp = fibs[i - 1].first + fibs[i - 2].first;
		cur = tmp % m;
		fibs.push_back(std::make_pair(tmp, cur));

		if (prev == 0 && cur == 1)
		{
			std::cout << i;
			break;
		}
	}

	prev = n % (fibs.size());
	std::cout << fibs[prev + 1].second;
}

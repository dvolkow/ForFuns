#include <iostream>
#include <set>

int main() 
{
	std::multiset<int> s; 
	std::set<int> v; 
	uint n, count = 0; int tmp;

	// -- read
	std::cin >> n;
	for (uint i = 0; i < n; ++i)
		std::cin >> tmp, s.insert(tmp), v.insert(tmp);

	for (auto i : v)
		if (s.count(i) > 1)
			count += (s.count(i) * (s.count(i) - 1)) / 2;
	std::cout << count;
}

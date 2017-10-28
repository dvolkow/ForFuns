#include <map>
#include <iostream>
#include <string>

std::map<uint, std::string> book;

int main()
{
	uint n, m;
	std::string buffer;
	std::cin >> n;
	for (uint i = 0; i < n; ++i)
	{
		std::cin >> buffer >> m;
		
		if (buffer == "add")
		{
			std::cin >> buffer; 
			if (book.count(m))
				book[m] = buffer;
			else 
				book.insert(std::make_pair(m, buffer));
		}
		else if (buffer == "del")
		{
			if (book.count(m))
				book.erase(m);
		}
		else if (buffer == "find")
		{
			if (book.count(m))
				std::cout << book[m] << std::endl;
			else 
				std::cout << "not found"<< std::endl;
		}
	}
}

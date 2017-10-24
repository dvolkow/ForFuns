#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string text, word;
    std::smatch m;
    std::getline(std::cin, text);
    std::regex ip("^\\d{1,3}(\\.\\d{1,3}){3}$");
    std::regex nums("(\\d{1,3})");

    if (std::regex_match(text, ip))
    {
        auto start = std::sregex_iterator(text.begin(), text.end(), nums);
        auto end = std::sregex_iterator();
        for (auto i = start; i != end; ++i)
        {
            if (!(std::stoi((*i)[1]) >= 0 && std::stoi((*i)[1]) < 256))
            {
                std::cout << "NO";
                return 0;
            }
        }
        std::cout << "YES";
    }
    else 
        std::cout << "NO";
}

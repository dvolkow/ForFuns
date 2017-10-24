#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string text, word;
    std::smatch m;
    std::getline(std::cin, text);
    std::regex words("(\\w+)(;|,| )*");

    auto start = std::sregex_iterator(text.begin(), text.end(), words);
    auto end = std::sregex_iterator();
    ushort length = 0;

    for (auto i = start; i != end; ++i)
    {
        auto match = *i;
        if (length < match[1].length())
            length = match[1].length(), word = match[1];
    }
    std::cout << word;
}

#include <iostream>
#include <set>
#include <string>
#include <regex>

std::set<std::string> dict;

int main() {
    std::string a;
    std::string text, word;
    std::smatch m;

    uint n, count = 0;
    std::cin >> n;
    for (uint i = 0; i < n; ++i)
        std::cin >> a, dict.insert(a);
    
    std::regex oneletter("^[a-z]*[A-Z][a-z]*$");
/*
    std::getline(std::cin, text);
    std::getline(std::cin, text);

    auto start = std::sregex_iterator(text.begin(), text.end(), words);
    auto end = std::sregex_iterator();
    for (auto i = start; i != end; ++i)
    {
        if (!dict.count((*i)[1]))
            ++count;
    }
    */
    while(std::cin >> text)
        if (!(dict.count(text)))
//            if (!std::regex_match(text, oneletter))
                ++count;
    std::cout << count - 1;
}


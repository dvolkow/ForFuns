#include <iostream>
#include <map>
#include <string>

typedef std::pair<std::string, std::string> pss;

std::map<std::string, std::string> dict;

int main() {
    std::string a, b;
    uint n;
    std::cin >> n;
    for (uint i = 0; i < n; ++i)
        std::cin >> a >> b, dict.insert(pss(a, b)), dict.insert(pss(b, a));
    std::cin >> a;
    std::cout << dict[a];
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct pupil
{
    std::string lname, fname;
    ushort summary;

    pupil(const std::string & l, const std::string & f, const ushort s)  : lname(l), fname(f), summary(s) {}
}; 

std::vector<pupil> list;

bool less(const pupil & a, const pupil & b)
{
    return a.summary > b.summary;
}

int main() 
{
    uint n;
    ushort a, b, c;
    std::string lname, fname;
    std::cin >> n;
    for (uint i = 0; i < n; ++i)
        std::cin >> lname >> fname >> a >> b >> c, list.push_back(pupil(lname, fname, a + c + b));
    std::stable_sort(list.begin(), list.end(), less);
    for (uint i = 0; i < n; ++i)
        std::cout << list[i].lname << " " << list[i].fname << "\n";
}


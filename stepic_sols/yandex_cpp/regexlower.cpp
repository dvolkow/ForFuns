#include <iostream>
#include <regex>
#include <ctype.h>
#include <string>

int main()
{
   std::string text;
   std::cin >> text;
   std::regex tu("[a-z]"), tl("[A-Z]");
   if (std::regex_match(text, tu))
       std::cout << (char)std::toupper(text[0]);
   else if (std::regex_match(text, tl))
       std::cout << (char)std::tolower(text[0]);
   else 
       std::cout << text;
}

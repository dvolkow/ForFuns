#include <iostream>

int sum = 0;

void getsum()
{
    int number;
    std::cin >> number; 
    if (number == 0)
        return;
    else
        sum += number, getsum();
}

int main() {
    getsum();
    std::cout << sum;
}

#include <string>
#include <stdio.h>
#include <iostream>
#include <functional>
using std::cout;
void otherdef(int &t)
{
    cout << "lvalue\n";
}

void otherdef(const int &t)
{
    cout << "rvalue\n";
}

template <typename T>
void function(T &&t)
{
    otherdef(std::forward<T>(t));
}

int main()
{
    function(5);
    int  x = 1;
    function(x);

    int n = 10;
    int &num = n;
    function(num); // T 为 int&
    int &&num2 = 11;
    function(num2); // T 为 int &&
}
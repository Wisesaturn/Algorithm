#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x)
{
    int input = x;
    int isDivide = x % 10;

    while (x /= 10, x > 0)
        isDivide += x % 10;

    if (input % isDivide == 0)
        return true;
    else
        return false;
}
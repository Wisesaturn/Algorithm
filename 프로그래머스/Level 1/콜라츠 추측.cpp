#include <string>

using namespace std;

int solution(int num)
{
    int cnt = -1;

    while (cnt++, cnt < 500 && num != 1 && num > 0)
    {
        if (num % 2 == 0)
            num /= 2;
        else
        {
            num *= 3;
            num++;
        }
    }

    return num == 1 ? cnt : -1;
}
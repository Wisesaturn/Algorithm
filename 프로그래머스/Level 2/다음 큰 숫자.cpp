#include <string>
#include <vector>
#include <iostream>

using namespace std;

int func(int n)
{
    int count = 0;
    // 1. 처음에 n을 2진수로 변환하여 1의 갯수를 파악 (기준)
    // 1-1. 2진수 변환
    do
    {
        if (n % 2 != 0)
            count++;
        n /= 2;
    } while (n >= 1);

    // 1-2. 1의 갯수 파악
    return count;
}

int solution(int n)
{
    int correct = func(n);
    // 2. n+1부터 시작하여 수를 늘려간다.
    // 이 때, 1번에서 계산했던 갯수가 같아질 때까지 늘려간다.
    while (true)
    {
        if (correct == func(++n))
        {
            // 3. 2번 과정에서 구한 값을 return
            return n;
        }
    }
}
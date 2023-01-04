#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int cnt = 0;

    while (cnt++)
    {
        if (n % cnt == 1)
            return cnt;
    }
}
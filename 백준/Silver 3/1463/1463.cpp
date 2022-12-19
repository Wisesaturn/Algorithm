#include <iostream>

using namespace std;

int dp[1000000];

int main(int argc, char *argv[])
{
    int isNumber;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= 1000000; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
        {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }

        if (i % 2 == 0)
        {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
    }

    cin >> isNumber;
    cout << dp[isNumber] << endl;

    return 0;
}
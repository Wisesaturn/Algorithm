#include <iostream>
#include <cstring>

using namespace std;

long long dp[35];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, cnt = 0;
    cin >> N;

    memset(&dp, 0, sizeof(dp));
    dp[0] = 1;

    while (cnt++, N >= cnt)
    {
        for (int i = 1; i <= cnt / 2; i++)
        {
            dp[cnt] += dp[cnt - i] * dp[i - 1];
        }
        dp[cnt] *= 2;

        if (cnt % 2 == 1)
            dp[cnt] += dp[cnt / 2] * dp[cnt / 2];
    }

    cout << dp[N];

    return 0;
}
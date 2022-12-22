#include <iostream>
#include <algorithm>

using namespace std;

int dp[100000];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i <= 100000; i++)
        dp[i] = 99999;

    int n;
    cin >> n;

    dp[2] = dp[5] = 1;
    dp[4] = 2;

    for (int i = 6; i <= n; i++)
        dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);

    if (dp[n] >= 99999)
        cout << "-1\n";
    else
        cout << dp[n] << "\n";

    return 0;
}
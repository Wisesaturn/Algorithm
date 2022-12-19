#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000];

int main(int argc, char *argv[])
{
    int isRock;
    string result;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < 1000; i++)
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);

    cin >> isRock;
    result = (dp[isRock] % 2 == 0) ? "CY" : "SK";
    cout << result << endl;

    return 0;
}
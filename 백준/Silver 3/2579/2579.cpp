#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[300];

int main(int argc, char *argv[])
{
    int isCase;
    vector<int> isStep;
    cin >> isCase;

    for (int i = 0; i < isCase; i++)
    {
        int temp;
        cin >> temp;
        isStep.push_back(temp);
    }

    dp[0] = isStep[0];
    dp[1] = max(isStep[1], isStep[0] + isStep[1]);
    dp[2] = max(isStep[0] + isStep[2], isStep[1] + isStep[2]);

    for (int i = 3; i < isCase; i++)
        dp[i] = max(dp[i - 2] + isStep[i], isStep[i - 1] + isStep[i] + dp[i - 3]);

    cout << dp[isCase - 1] << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int dp[40] = {0, 1, 1};

int main(int argc, char *argv[])
{
    int isCount;
    vector<int> isCase;
    cin >> isCount;

    for (int i = 0; i < isCount; i++)
    {
        int temp;
        cin >> temp;
        isCase.push_back(temp);
    }

    for (int i = 3; i <= 40; i++)
        dp[i] = dp[i - 2] + dp[i - 1];

    for (int i = 0; i < isCount; i++)
    {
        if (isCase[i] == 0)
            cout << 1 << " " << 0 << endl;
        else if (isCase[i] == 1)
            cout << 0 << " " << 1 << endl;
        else
        {
            cout << dp[isCase[i] - 1] << " " << dp[isCase[i]] << endl;
        }
    }

    return 0;
}
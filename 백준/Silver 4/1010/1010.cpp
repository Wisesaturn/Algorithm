#include <iostream>
#include <vector>

using namespace std;

int dp[30][30];

int main(int argc, char *argv[])
{
    int isCase;
    vector<int> West;
    vector<int> East;

    for (int i = 1; i < 30; i++)
    {
        dp[i][1] = i;

        for (int j = 2; j < 30; j++)
        {
            if (i <= 1)
                continue;
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cin >> isCase;

    for (int i = 0; i < isCase; i++)
    {
        int n, m;
        cin >> n >> m;
        West.push_back(n);
        East.push_back(m);
    }

    for (int i = 0; i < isCase; i++)
        cout << dp[East[i]][West[i]] << endl;

    return 0;
}
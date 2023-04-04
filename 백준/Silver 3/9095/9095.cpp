#include <iostream>
#include <vector>

using namespace std;

int dp[12];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T;
  cin >> T;

  for (int i = 0; i <= 11; i++)
  {
    if (i <= 2)
    {
      dp[i] = i;
      continue;
    }

    if (i == 3)
    {
      dp[i] = 4;
      continue;
    }

    dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 2];
  }

  while (T--)
  {
    int tmp;
    cin >> tmp;

    cout << dp[tmp] << endl;
  }
  return 0;
}

// 8분 소요
// 조합론처럼 밑의 경우가 되는 경우 + 안 되는 경우로 분리하여 생각하면 편하다
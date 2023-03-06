#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, max = 0;
  cin >> N;

  vector<int> boxs(1);

  while (N--)
  {
    int tmp;
    cin >> tmp;
    boxs.push_back(tmp);
  }

  dp[1] = 1;

  for (int i = 2; i < boxs.size(); i++)
  {
    dp[i] = 1;

    for (int j = 1; j < i; j++)
      if (boxs[j] < boxs[i] && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;

    if (max < dp[i])
      max = dp[i];
  }

  cout << max;

  return 0;
}
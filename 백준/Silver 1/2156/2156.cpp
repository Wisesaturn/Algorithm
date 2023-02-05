#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> wines(N, 0);
  vector<int> dp(N, 0);

  for (int &wine : wines)
    cin >> wine;

  dp[0] = wines[0];

  if (N > 1)
    dp[1] = wines[0] + wines[1];

  if (N > 2)
    dp[2] = max(max(wines[1] + wines[2], wines[0] + wines[2]), dp[1]);

  for (int i = 3; i < N; i++)
    dp[i] = max(max(dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]), dp[i - 1]);

  cout << dp[N - 1];

  return 0;
}

// 처음에 wines[0]를 고려하지 않는 경우의 수를 배제함
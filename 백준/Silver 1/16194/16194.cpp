#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, K = 0;
  cin >> N;
  vector<int> P(N);
  vector<int> dp(N + 1, 0);
  // dp : 카드 갯수에 따른 최솟값

  for (int &i : P)
    cin >> i;

  while (K++, K <= N)
  {
    dp[K] = P[K - 1];
    for (int i = 1; i <= K; i++)
      dp[K] = min(dp[K], dp[i] + dp[K - i]);
  }

  cout << dp[N];

  return 0;
}
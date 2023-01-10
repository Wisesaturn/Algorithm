#include <iostream>
#include <cmath>

using namespace std;

long long dp[21] = {
    1,
    2,
    4,
    7,
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, Sum = 0;
  cin >> N;

  for (int i = 4; i < N; i++)
  {
    dp[i] = dp[i - 1] * 2;
    if (i % 2 != 0)
      dp[i] -= (dp[i - 4] + dp[i - 5]);
      // 짝수해일 때, 3년 전과 4년 전에 생긴 마릿수만큼 빼기
  }

  cout << dp[N - 1];

  return 0;
}
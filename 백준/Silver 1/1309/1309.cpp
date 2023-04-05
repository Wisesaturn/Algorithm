#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;

  int dp[100001][3];
  // dp[?][0] : 왼쪽 배치, dp[?][1] : 오른쪽 배치, dp[?][2] : 배치 X

  dp[1][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;

  for (int i = 2; i <= 100000; i++)
  {
    dp[i][0] = (dp[i - 1][2] + dp[i - 1][1]) % 9901;
    dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % 9901;
    dp[i][2] = (dp[i - 1][2] + dp[i - 1][1] + dp[i - 1][0]) % 9901;
  }

  int ans = dp[N][0] + dp[N][1] + dp[N][2];
  cout << ans % 9901;
  
  return 0;
}

// 45분 소요
// 경우의 수를 나눌 때 확실하게 나눠야 하는 상황이 온다면 2차원 배열로 dp를 만들자
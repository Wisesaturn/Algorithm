#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long dp[101] = {
      0,
      1,
      1,
      1,
      2,
      2,
  };

  for (long long i = 6; i <= 101; i++)
    dp[i] = dp[i - 1] + dp[i - 5];

  long long N;
  cin >> N;

  while (N--)
  {
    long long tmp;
    cin >> tmp;
    cout << dp[tmp] << "\n";
  }

  return 0;
}
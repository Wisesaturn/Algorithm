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
  vector<int> p(N);
  vector<int> dp(N);

  for (int &i : p)
    cin >> i;

  sort(p.begin(), p.end());

  dp[0] = p[0];
  int sum = dp[0];

  for (int i = 1; i < N; i++)
  {
    dp[i] = dp[i - 1] + p[i];
    sum += dp[i];
  }

  cout << sum;

  return 0;
}
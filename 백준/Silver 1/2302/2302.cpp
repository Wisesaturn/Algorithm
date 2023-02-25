#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int Fibonacci(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M, cnt = 0, ans = 1;

  cin >> N;
  vector<int> dp(N + 1, 0);
  queue<int> q;
  cin >> M;

  while (M--)
  {
    int tmp;
    cin >> tmp;
    dp[tmp] = -1;
  }

  for (int i = 1; i <= N; i++)
  {
    if (dp[i] == -1)
    {
      q.push(cnt == 0 ? 1 : cnt);
      cnt = 0;
      continue;
    }

    cnt++;

    if (i == N)
    {
      q.push(cnt == 0 ? 1 : cnt);
      break;
    }
  }

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    ans *= Fibonacci(cur);
  }

  cout << ans;

  return 0;
}
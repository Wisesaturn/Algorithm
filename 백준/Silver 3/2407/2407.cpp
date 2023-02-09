#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dp[101][101];

string add(string num1, string num2)
{
  string ans = "";
  int sum = 0;
  int length = max(num1.size(), num2.size());

  for (int i = 0; i < length || sum; i++)
  {
    for (string num : {num1, num2})
      if (num.size() > i)
        sum += num[i] - '0';

    ans += ((sum % 10) + '0');
    sum /= 10;
  }

  return ans;
}

string combination(int n, int r)
{
  if (n == r || r == 0)
    return "1";
  string &memo = dp[n][r];

  if (memo != "")
    return memo;

  memo = add(combination(n - 1, r), combination(n - 1, r - 1));

  return memo;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  string ans = combination(N, M);
  reverse(ans.begin(), ans.end());
  cout << ans;

  return 0;
}
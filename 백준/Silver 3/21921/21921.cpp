#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, X, ans = 0, days = 0;
  int start = 0, end = 0, cnt = 0;
  cin >> N >> X;
  vector<int> visitor(N);

  for (int &day : visitor)
    cin >> day;

  while (start < N && end < N)
  {
    if (end - start < X)
    {
      end++;
      cnt += visitor[end - 1];
    }
    else
    {
      start++;
      cnt -= visitor[start - 1];
    }

    if (ans < cnt)
    {
      ans = cnt;
      days = 1;
    }
    else if (ans == cnt)
      days++;
  }

  if (ans != 0)
  {
    cout << ans << "\n";
    cout << days << "\n";
  }
  else
    cout << "SAD";

  return 0;
}
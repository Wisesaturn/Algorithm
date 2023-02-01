#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, ans = 0, cnt = 0;
  cin >> N;

  vector<int> list(N, 0);

  for (int &i : list)
    cin >> i;

  sort(list.begin(), list.end(), greater<>());

  for (int e : list)
  {
    if (cnt == 2)
    {
      cnt = 0;
      continue;
    }

    ans += e;
    cnt++;
  }

  cout << ans;

  return 0;
}
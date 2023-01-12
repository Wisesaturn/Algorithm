#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, sum = 0, ans = 0;
  cin >> N;
  vector<int> p(N);

  for (int &i : p)
    cin >> i;

  sort(p.begin(), p.end());

  for (int i = 0; i < N; i++)
  {
    sum += p[i];
    ans += sum;
  }

  cout << ans;

  return 0;
}
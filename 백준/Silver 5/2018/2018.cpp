#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long N, cnt = 0, sum = 0;
  cin >> N;

  long long s = 1, e = 1;

  while (s <= e, e <= N + 1)
  {
    if (sum < N)
      sum += e++;
    else if (sum > N)
      sum -= s++;
    else if (sum == N)
    {
      cnt++;
      sum += e++;
    }
  }

  cout << cnt;

  return 0;
}
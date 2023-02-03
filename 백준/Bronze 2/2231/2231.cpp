#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, ans = 0;
  cin >> N;
  int original = N;

  while (N--)
  {
    int sum = N, tmp = N;

    while (tmp > 0)
    {
      sum += tmp % 10;
      tmp /= 10;

      if (sum > original)
        break;
    }

    if (sum == original)
      ans = N;
  }

  cout << ans;

  return 0;
}
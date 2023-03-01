#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;

  long long ans = 1;

  for (long long i = 1; i <= N; i++)
  {
    ans *= i;
    ans %= 100000000;
    while (ans % 10 == 0)
      ans /= 10;
  }

  cout << ans % 10;

  return 0;
}
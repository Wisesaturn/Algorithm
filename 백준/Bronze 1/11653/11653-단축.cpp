#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long N;
  cin >> N;

  while (N > 1)
    for (long long i = 2; i <= N;)
      if (N % i == 0)
      {
        cout << i << "\n";
        N /= i;
      }
      else
        i++;

  return 0;
}
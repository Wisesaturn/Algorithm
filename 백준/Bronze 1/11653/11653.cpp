#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long N;
  long long tmp = 2;
  cin >> N;

  while (N > 1)
  {
    if (N % tmp == 0)
    {
      N /= tmp;
      cout << tmp << "\n";
      tmp = 2;
      continue;
    }
    else
      tmp++;

    if (tmp > N)
      break;
  }

  return 0;
}
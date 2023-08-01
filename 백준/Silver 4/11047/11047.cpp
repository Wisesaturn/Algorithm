#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, K, sum = 0, count = 0;
  cin >> N >> K;

  vector<int> coins(N);

  for (int &coin : coins)
    cin >> coin;

  for (int i = N - 1; i >= 0; i--)
  {
    while (sum + coins[i] <= K)
    {
      count++;
      sum += coins[i];
    }

    if (sum == K)
    {
      cout << count;
      break;
    }
  }

  return 0;
}
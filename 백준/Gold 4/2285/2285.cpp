#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 0. settings
  long long N, maxH = 0, cntH = 0;
  int targetTown;
  vector<pair<long long, long long>> towns;
  cin >> N;

  while (N--)
  {
    long long X, A;
    cin >> X >> A;
    towns.push_back({X, A});
    maxH += A;
  }

  sort(towns.begin(), towns.end());

  // 1. 총 사람의 수의 절반이 되는 지점 찾기
  for (auto t : towns)
  {
    cntH += t.second;

    if (maxH % 2 == 0)
    {
      if (cntH >= (maxH / 2))
      {
        targetTown = t.first;
        break;
      }
    }
    else
    {
      if (cntH >= (maxH / 2 + 1))
      {
        targetTown = t.first;
        break;
      }
    }
  }

  cout << targetTown << "\n";

  return 0;
}
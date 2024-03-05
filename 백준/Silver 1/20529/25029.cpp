#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getDistance(string &a, string &b)
{
  int dist = 0;
  for (int i = 0; i < 4; i++)
    if (a[i] != b[i])
      dist++;
  return dist;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T;
  cin >> T;

  while (T--)
  {
    // 0. settings
    int N, minSum = 99999999;
    string s;
    vector<string> MBTI;
    vector<int> dist;

    cin >> N;

    for (int k = 0; k < N; k++)
    {
      cin >> s;
      MBTI.push_back(s);
    }

    // 1. MBTI 정렬 (같은 MBTI 끼리 모이게)
    sort(MBTI.begin(), MBTI.end());

    // 2-1. MBTI가 32개보다 많다면
    if (N > 32)
    {
      cout << 0 << "\n";
    }
    else
    {
      // 2-3. 최소값 찾기 (bruth-force)
      for (int i = 0; i < N; i++)
      {
        for (int j = 0; j < N; j++)
        {
          if (i == j)
            continue;
          for (int k = 0; k < N; k++)
          {
            if (k == i || k == j)
              continue;
            int d1 = getDistance(MBTI[i], MBTI[j]);
            int d2 = getDistance(MBTI[j], MBTI[k]);
            int d3 = getDistance(MBTI[i], MBTI[k]);
            int total = d1 + d2 + d3;
            if (minSum > total)
              minSum = total;
          }
        }
      }

      // 3. 결과 출력
      cout << minSum << "\n";
    }
  }

  return 0;
}
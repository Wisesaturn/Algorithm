#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(int N, int number)
{
  if (N == number)
    return 1;
  vector<set<int>> dp(9, set<int>());

  dp[0].insert(0);
  dp[1].insert(N);

  for (int i = 2; i <= 8; i++)
  {
    string tmp = "";
    for (int j = 0; j < i; j++)
      tmp += N + '0';

    // 1. 완전체
    dp[i].insert(stoi(tmp));

    // 2. 사칙연산
    for (int a = 1; a < i; a++)
    {
      for (int b = 1; b < i; b++)
      {
        if (a + b != i)
          continue;

        for (int d1 : dp[a])
        {
          for (int d2 : dp[b])
          {
            dp[i].insert(d1 + d2);
            dp[i].insert(d1 * d2);
            if (d1 - d2 > 0)
            {
              dp[i].insert(d1 - d2);
            }
            if (d2 != 0 && d1 / d2 > 0)
            {
              dp[i].insert(d1 / d2);
            }
          }
        }
      }
    }
  }

  for (int t = 1; t <= 8; t++)
  {
    if (dp[t].find(number) != dp[t].end())
      return t;
  }

  return -1;
}

// 과정이 정말 생각이 나지 않는다
// 그럴 땐 일단 써보기라도 하자
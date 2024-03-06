#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
  if (a[0] == b[0])
    return a[1] > b[1];
  return a[0] > b[0];
}

int solution(vector<vector<int>> routes)
{
  int cnt = 0, target = 30001;

  // 1. 끝 점을 기준으로 정렬한다
  sort(routes.begin(), routes.end(), compare);

  // 2. 카메라를 설치하는 기준을 정한다
  for (int i = 0; i < routes.size(); i++)
  {
    int start = routes[i][0];
    int end = routes[i][1];
    // 마지막 routes는 따로 체크
    if (i == routes.size() - 1)
    {
      if (target > end)
        cnt++;
      break;
    }

    int nextStart = routes[i + 1][0];
    int nextEnd = routes[i + 1][1];
    int nextTarget = start;

    if (target <= end)
      continue;

    if (target > nextTarget)
    {
      cnt++;
      target = nextTarget;
    }
  }

  return cnt;
}

// 소요시간 : 1h 20m
// 핵심 : 타임라인으로 나타낸 여러 개체들을 최소한으로 선택할 때,
// 시작점을 타겟으로 잡고 그 이후에 끝점이 시작점과 동일해 질 때까지 카운팅하는 방법
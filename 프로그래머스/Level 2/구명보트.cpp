#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit)
{
  int cnt = 0;
  deque<int> dq;

  sort(people.begin(), people.end());

  for (auto p : people)
    dq.push_back(p);

  while (!dq.empty())
  {
    auto max_cur = dq.back();
    auto min_cur = dq.front();

    dq.pop_back();

    if (!dq.empty())
    {
      if (min_cur + max_cur <= limit)
        dq.pop_front();
    }

    cnt++;
  }

  return cnt;
}

// 알고리즘 짜는 데 헷갈렸다.
// 몸무게가 제일 많이 나가는 사람은 몸무게가 제일 적은 사람과 나갈 확률이 더 높다는 걸 체크하자
// 타임라인 같이 선을 긋고 몸무게별로 사례를 들어 체크할 것
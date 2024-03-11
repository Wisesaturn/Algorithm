#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comparePQ
{
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    if (a.second == b.second)
      return a.first < b.first;
    return a.second > b.second;
  }
};

bool compare(pair<int, int> &a, pair<int, int> &b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 0. settings
  int N, ans = 0, date = 0, maxDate = 0, startDay = 0, endDay = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, comparePQ> plans;
  vector<pair<int, int>> dates;
  cin >> N;

  while (N--)
  {
    int s, e;
    cin >> s >> e;
    dates.emplace_back(s, e);
  }

  sort(dates.begin(), dates.end(), compare);
  startDay = dates[0].first;
  endDay = dates[0].second;

  for (auto d : dates)
  {
    cout << "(d)" << d.first << " " << d.second << endl;
    // 비어져 있는 일정이 있는지 체크
    // 비어져 있는 일정으로 다시 일정칸을 넣을 수 있게

    while (!plans.empty() && plans.top().second < d.first)
    {
      // cout << "(plans pop)" << plans.top().first << " " << plans.top().second << " " << date << endl;
      plans.pop();
      date--;
    }

    if (plans.empty() && d.first > endDay + 1)
    {
      // 연속된 일정이 종료됐으므로 코팅 영역 계산
      int width = (endDay - startDay + 1);
      int size = width * maxDate;
      ans += size;
      // cout << "(reset)" << startDay << " " << endDay << " " << size << " " << maxDate << endl;
      // 시작 시간 리셋
      startDay = d.first;
      endDay = d.first;
      maxDate = 0;
    }

    plans.push(d);
    date++;
    maxDate = max(date, maxDate);
    endDay = d.second > endDay ? d.second : endDay;
    // cout << "(start/end)" << startDay << " " << endDay << " " << date << endl;
  }

  // 마지막 남은 코팅 영역 계산
  int width = (endDay - startDay + 1);
  int size = width * maxDate;
  ans += size;
  // cout << "(end)" << startDay << " " << endDay << " " << size << " " << maxDate << endl;

  // 결과 출력
  cout << ans;

  return 0;
}
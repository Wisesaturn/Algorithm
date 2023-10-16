#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
  int start;
  int end;

  Meeting(int s, int e) : start(s), end(e){};
};

bool compare(Meeting a, Meeting b)
{
  if (a.end == b.end)
    return a.start < b.start;
  return a.end < b.end;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, iter = 0, ans = 0;
  cin >> N;

  vector<Meeting> list;

  while (N--)
  {
    int s, e;
    cin >> s >> e;
    list.emplace_back(s, e);
  }

  // 종료 시간 기준으로 정리하되 시간이 가장 적은 순서가 맨 앞으로
  sort(list.begin(), list.end(), compare);
  int boundary = list[iter].end;
  ans++;

  while (++iter, iter < list.size())
  {
    int start = list[iter].start;
    int end = list[iter].end;

    if (start >= boundary)
    {
      ans++;
      boundary = end;
    }
  }

  cout << ans;

  return 0;
}
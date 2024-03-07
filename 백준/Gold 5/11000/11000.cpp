#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare
{
  bool operator()(pair<long long, long long> &a, pair<long long, long long> &b)
  {
    if (a.second == b.second)
      return a.first < b.first;
    return a.second > b.second;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long N;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, compare> rooms;
  vector<pair<long long, long long>> lectures;
  cin >> N;

  // 0. settings
  while (N--)
  {
    long long s, t;
    cin >> s >> t;
    lectures.emplace_back(s, t);
  }
  // cout << "---" << endl;

  sort(lectures.begin(), lectures.end());

  for (auto l : lectures)
  {
    // cout << l.first << " " << l.second << endl;
    if (!rooms.empty() && rooms.top().second <= l.first)
      rooms.pop();
    rooms.push(l);
  }

  cout << rooms.size() << "\n";

  return 0;
}

// 걸린 시간 : 1h 10m
// 요약 : 비어있는 방을 찾을 때, 수업이 끝나는 시간이 가장 빠른 수업을 찾고
// 그 수업과 비교하여 강의실을 만들지 말지만 정하면 되는 문제였다.
// 여기서 if가 아닌 while을 사용하여서 모든 수업을 다 제거해버린 탓에 오류가 나왔다.
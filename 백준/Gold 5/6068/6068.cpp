#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, time = 9999999;
  cin >> N;

  vector<pair<int, int>> jobs(N);

  for (int i = 0; i < N; i++)
  {
    int t, s;
    cin >> t >> s;
    jobs[i] = {s, t};
  }

  sort(jobs.begin(), jobs.end());

  for (int j = N - 1; j >= 0; j--)
  {
    int fin = jobs[j].first;
    int doing = jobs[j].second;

    time = min(fin, time);
    time -= doing;
  }

  cout << ((time < 0) ? -1 : time);

  return 0;
}

// 1. 가장 마지막에 끝낼 수 있는 시간을 구한다
// 2. 그 시간에서 수행하는 시간을 빼면, 농부가 놀 수 있는 최대의 시간이다.
// 3. 그 다음으로 마지막에 끝낼 수 있는 시간을 구하고, 2번에서 구한 시간과 비교한다.
// 4. 둘 중 더 적은 시간을 기준으로 잡는다.
// 5. 2-4번을 반복하여 최종으로 시간이 곧 결과값이다.
// 5-2. 이 값이 마이너스가 나면 불가능하다!
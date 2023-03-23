#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, pair<int, int>>> shoutcuts;
int ans = 99999;
int N, D;

void bfs()
{
  queue<pair<int, int>> q;
  int sumLength = 0, start = 0;
  q.push({start, sumLength});

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    int now = cur.first;
    int sum = cur.second;

    if (now >= D)
    {
      if (now == D && ans > sum)
        ans = sum;
      continue;
    }

    for (auto way : shoutcuts)
    {
      int point = way.first;
      auto info = way.second;

      if (point != now)
        continue;

      q.push({info.second, sum + info.first});
    }

    q.push({now + 1, sum + 1});
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> D;

  while (N--)
  {
    int start, end, length;
    cin >> start >> end >> length;

    shoutcuts.push_back({start, {length, end}});
  }

  bfs();

  cout << ans;

  return 0;
}
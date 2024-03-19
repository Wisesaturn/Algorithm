#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>

using namespace std;

int ans = 0;
unordered_map<int, bool> visited;
unordered_map<int, int> ladders;
unordered_map<int, int> snakes;

void bfs()
{
  deque<pair<int, int>> q;

  for (int i = 1; i <= 6; i++)
    q.push_back({i + 1, 1});

  // cout << "---" << endl;
  while (!q.empty())
  {
    auto cur = q.front();
    q.pop_front();

    // cout << cur.first << " " << cur.second << endl;

    // finish condition
    if (cur.first == 100)
    {
      ans = cur.second;
      break;
    }

    if (visited[cur.first])
      continue;

    visited[cur.first] = true;

    // if it's ladder or snake
    if (ladders[cur.first])
    {
      q.push_front({ladders[cur.first], cur.second});
      // cout << "ladders : " << ladders[cur.first] << endl;
    }
    else if (snakes[cur.first])
    {
      q.push_front({snakes[cur.first], cur.second});
      // cout << "snakes : " << snakes[cur.first] << endl;
    }
    else
    {
      for (int i = 1; i <= 6; i++)
        q.push_back({cur.first + i, cur.second + 1});
    }
  }

  return;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 0. settings
  int N, M;
  cin >> N >> M;

  while (N--)
  {
    int x, y;
    cin >> x >> y;
    ladders[x] = y;
  }

  while (M--)
  {
    int u, v;
    cin >> u >> v;
    snakes[u] = v;
  }

  // 1. bfs
  bfs();

  // answer
  cout << ans << "\n";

  return 0;
}
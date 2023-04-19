#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int ans = 0;
unordered_map<int, bool> visited;

void bfs(int start, int end)
{
  if (start == end)
    return;

  queue<pair<int, int>> q;
  q.push({1, start + 1});
  q.push({1, start - 1});
  q.push({1, start * 2});

  visited[start + 1] = true;
  visited[start - 1] = true;
  visited[start * 2] = true;

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    int time = cur.first;
    int location = cur.second;

    if (location == end)
    {
      ans = time;
      break;
    }

    int nx = location + 1;
    if (nx >= 0 && nx <= 100000 && !visited[nx])
    {
      visited[nx] = true;
      q.push({time + 1, nx});
    }

    nx = location - 1;
    if (nx >= 0 && nx <= 100000 && !visited[nx])
    {
      visited[nx] = true;
      q.push({time + 1, nx});
    }

    nx = location * 2;
    if (nx >= 0 && nx <= 100000 && !visited[nx])
    {
      visited[nx] = true;
      q.push({time + 1, nx});
    }
  }

  return;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  bfs(N, K);

  cout << ans;
  return 0;
}
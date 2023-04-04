#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N;

vector<vector<int>> map;
unordered_map<int, unordered_map<int, bool>> visited;

int ans = 0, cnt = 0, maxh = 0;

void reset()
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      visited[i][j] = false;
  cnt = 0;
}

void bfs(int height, pair<int, int> point)
{
  queue<pair<int, int>> q;
  q.push(point);

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || map[nx][ny] <= height)
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;

  map.resize(N, vector<int>(N));

  for (vector<int> &row : map)
    for (int &height : row)
    {
      cin >> height;

      if (height > maxh)
        maxh = height;
    }

  for (int i = 0; i <= maxh; i++)
  {
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        if (visited[j][k] || map[j][k] <= i)
          continue;

        bfs(i, {j, k});
        cnt++;
      }
    }

    if (ans < cnt)
      ans = cnt;
    reset();
  }

  cout << ans;

  return 0;
}

// 26분 소요
// 비가 내리지 않을 때도 고려해야 한다
// 굳이 높이를 100까지 돌릴 필요도 없으며 필요한 좌표마다 bfs를 적용하면 된다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, sx, sy;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<vector<int>> map(0, vector<int>(0));
vector<vector<int>> dist(0, vector<int>(0));

struct point
{
  int x, y;
};

int bfs(point start)
{
  queue<point> q;
  q.push(start);
  dist[start.x][start.y] = 0;

  while (!q.empty())
  {
    point cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m || dist[nx][ny] != -1 || map[nx][ny] != 1)
        continue;

      q.push({nx, ny});
      dist[nx][ny] = dist[cur.x][cur.y] + 1;
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (map[i][j] == 0)
        dist[i][j] = 0;

  return 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> n >> m;
  map.resize(n, vector<int>(m, -1));
  dist.resize(n, vector<int>(m, -1));

  for (vector<int> &i : map)
    for (int &j : i)
      cin >> j;

  for (vector<int> &i : map)
  {
    if (find(i.begin(), i.end(), 2) != i.end())
    {
      sy = find(i.begin(), i.end(), 2) - i.begin();
      sx = &i - &map[0];
      break;
    }
  }

  bfs({sx, sy});

  for (vector<int> &i : dist)
  {
    for (int &j : i)
      cout << j << " ";
    cout << "\n";
  }

  return 0;
}
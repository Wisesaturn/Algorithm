#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// struct point 구조체 방법 말고 pair를 통해 해보았음

int dx[] = {1, 0};
int dy[] = {0, 1};

bool bfs(vector<vector<int>> map, vector<vector<bool>> v)
{
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));

  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    v[cur.first][cur.second] = true;
    q.pop();

    for (int i = 0; i < 2; i++)
    {
      int nx = cur.first + dx[i] * map[cur.first][cur.second];
      int ny = cur.second + dy[i] * map[cur.first][cur.second];

      if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map.size() || v[nx][ny] == true)
        continue;

      if (map[nx][ny] == -1)
        return true;

      q.push(make_pair(nx, ny));
    }
  }

  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;
  vector<vector<int>> map(N, vector<int>(N, -999));
  vector<vector<bool>> v(N, vector<bool>(N, false));

  for (vector<int> &i : map)
    for (int &j : i)
      cin >> j;

  bfs(map, v) ? cout << "HaruHaru" : cout << "Hing";
  return 0;
}

// but 메모리 초과 -> dfs로 전환
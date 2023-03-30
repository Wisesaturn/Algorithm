#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> viruses;
int ans = 0;
int N, M;

struct Point
{
  int x;
  int y;
  vector<pair<int, int>> setWalls;

  Point(int X, int Y) : x(X), y(Y){};

  void set(int a, int b)
  {
    if (setWalls.size() < 3)
      setWalls.push_back({a, b});
  }

  int size()
  {
    return setWalls.size();
  }

  vector<pair<int, int>> walls()
  {
    return setWalls;
  }

  bool check(int a, int b)
  {
    for (auto point : setWalls)
      if (point.first == a && point.second == b)
        return true;

    return false;
  }
};

vector<unordered_map<int, bool>> visited;
vector<unordered_map<int, bool>> checked;

pair<int, int> d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int counted(const vector<pair<int, int>> &walls)
{
  int cnt = 0;
  vector<unordered_map<int, bool>> visit;

  visit.resize(N);

  for (auto point : walls)
    map[point.first][point.second] = 1;

  queue<pair<int, int>> q;

  for (auto virus : viruses)
    q.push(virus);

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (auto direction : d)
    {
      int nx = cur.first + direction.first;
      int ny = cur.second + direction.second;

      cout << nx << " " << ny << endl;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] || map[nx][ny] == 2 || map[nx][ny] == 1)
        continue;

      visit[nx][ny] = true;
      cnt++;
    }
  }

  for (auto point : walls)
    map[point.first][point.second] = 0;

  return cnt;
}

void bfs()
{
  queue<Point> q;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == 2)
      {
        Point virus(i, j);
        viruses.push_back({i, j});
        q.push(virus);
      }

  while (!q.empty())
  {
    Point cur = q.front();
    q.pop();

    if (cur.size() == 3)
    {

      int tmp = counted(cur.walls());
      if (ans < tmp)
        ans = tmp;

      continue;
    }

    for (auto direction : d)
    {
      int nx = cur.x + direction.first;
      int ny = cur.y + direction.second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || checked[nx][ny] || visited[nx][ny] || map[nx][ny] == 2 || map[nx][ny] == 1)
        continue;

      if (cur.size() < 3 && !cur.check(nx, ny) && map[nx][ny] == 0)
      {
        cur.set(nx, ny);
        cur.x = nx;
        cur.y = ny;
        checked[nx][ny] = true;
        q.push(cur);
        cur.x -= direction.first;
        cur.y -= direction.second;
      }

      if (map[nx][ny] == 0)
      {
        cur.x = nx;
        cur.y = ny;
        visited[nx][ny] = true;
        q.push(cur);
        cur.x -= direction.first;
        cur.y -= direction.second;
      }
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  map.resize(N, vector<int>(M, 0));
  visited.resize(N);
  checked.resize(N);

  for (vector<int> &row : map)
    for (int &element : row)
      cin >> element;

  bfs();

  cout << ans;

  return 0;
}

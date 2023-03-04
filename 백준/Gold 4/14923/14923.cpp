#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
  bool isBroken;
  int x;
  int y;
};

vector<vector<int>> maps;
vector<vector<int>> paths;
vector<unordered_map<int, bool>> visitedIsBroken;
vector<unordered_map<int, bool>> visitedIsNotBroken;

int N, M;
int Hx, Hy, Ex, Ey;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs()
{
  queue<Node> q;
  q.push({false, Hx - 1, Hy - 1});

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    if (cur.x == Ex - 1 && cur.y == Ey - 1)
      return paths[cur.x][cur.y];

    for (int i = 0; i < 4; i++)
    {
      int nx = dx[i] + cur.x;
      int ny = dy[i] + cur.y;

      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;

      if (maps[nx][ny] == 0)
      {
        if (visitedIsBroken[nx][ny])
          continue;

        paths[nx][ny] = paths[cur.x][cur.y] + 1;
        visitedIsBroken[nx][ny] = true;
        q.push({cur.isBroken, nx, ny});
      }
      else if (maps[nx][ny] == 1 && !cur.isBroken)
      {
        if (visitedIsNotBroken[nx][ny])
          continue;

        paths[nx][ny] = paths[cur.x][cur.y] + 1;
        visitedIsNotBroken[nx][ny] = true;
        q.push({true, nx, ny});
      }
    }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;
  cin >> Hx >> Hy >> Ex >> Ey;

  maps.resize(N, vector<int>(M, 0));
  paths.resize(N, vector<int>(M, 0));
  visitedIsBroken.resize(N);
  visitedIsNotBroken.resize(N);

  for (vector<int> &row : maps)
    for (int &location : row)
      cin >> location;

  cout << bfs();

  // for (vector<int> row : paths)
  // {
  //   for (int location : row)
  //     cout << location << " ";
  //   cout << endl;
  // }

  return 0;
}
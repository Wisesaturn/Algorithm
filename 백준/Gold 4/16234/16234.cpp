#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, unordered_map<int, bool>> visited;

int N, L, R;
int rationSum = 0, rationCount = 0;
int ans = 0;
bool checked = false;
bool isVisitedStandard = true;
vector<vector<int>> maps;
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
  visited[x][y] = isVisitedStandard;
  rationCount++;
  rationSum += maps[x][y];

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == isVisitedStandard)
      continue;

    int CheckedData = 0;

    if (maps[nx][ny] > maps[x][y])
      CheckedData = maps[nx][ny] - maps[x][y];
    else
      CheckedData = maps[x][y] - maps[nx][ny];

    if (CheckedData >= L && CheckedData <= R)
    {
      checked = true;
      dfs(nx, ny);
      q.push({nx, ny});
    }
  }
}

void MovePeople(int x, int y)
{
  int setPeople = rationSum / rationCount;
  maps[x][y] = setPeople;

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    maps[cur.first][cur.second] = setPeople;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> L >> R;
  maps.resize(N, vector<int>(N, 0));

  for (vector<int> &row : maps)
    for (int &block : row)
      cin >> block;

  while (true)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (visited[i][j] == !isVisitedStandard)
        {
          dfs(i, j);
          MovePeople(i, j);
          rationSum = 0;
          rationCount = 0;
        }
      }
    }

    if (checked)
      ans++;
    else
      break;

    isVisitedStandard = !isVisitedStandard;
    checked = false;
  }

  cout << ans;

  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N, M, ans = 0;
vector<vector<int>> map;
unordered_map<int, unordered_map<int, bool>> visited;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void debug()
{
  cout << "----------------------------------------------------------------" << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

// void doDeclineHeight()
// {
//   int cnt = 0;

//   for (int i = 0; i < N; i++)
//   {
//     for (int j = 0; j < M; j++)
//     {
//       if (!visited[i][j] && !checked[i][j])
//         continue;

//       checked[i][j] = true;

//       for (int k = 0; k < 4; k++)
//       {
//         int px = i + dx[k];
//         int py = j + dy[k];

//         if (px < 0 || py < 0 || px >= N || py >= M || map[px][py] != 0 || checked[px][py])
//           continue;
//         cnt++;
//       }

//       map[i][j] = map[i][j] - cnt < 0 ? 0 : map[i][j] - cnt;
//       cnt = 0;
//     }
//   }
// }

void bfs(int x, int y)
{
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty())
  {
    auto cur = q.front();
    int cnt = 0;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (!visited[nx][ny] && map[nx][ny] == 0)
        cnt++;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || map[nx][ny] == 0)
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }

    map[cur.first][cur.second] = map[cur.first][cur.second] - cnt < 0 ? 0 : map[cur.first][cur.second] - cnt;
    cnt = 0;
  }
}

bool isDivided()
{
  int cnt = 0;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] != 0 && !visited[i][j])
      {
        if (cnt > 0)
          return true;
        bfs(i, j);
        cnt++;
      }

  // doDeclineHeight();
  // debug();

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (visited[i][j])
        visited[i][j] = false;

  if (cnt == 0)
  {
    ans = 0;
    return true;
  }

  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;
  map.resize(N, vector<int>(M));

  for (vector<int> &row : map)
    for (int &height : row)
      cin >> height;

  bool checked = isDivided();

  while (!checked)
  {
    ans++;
    checked = isDivided();
  }

  cout << ans;

  return 0;
}

// 48분 소요
// 제한시간이 1초인데, 소요시간이 988ms (거의 1초 가까이 됐다)
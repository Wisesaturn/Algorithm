#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<vector<int>> box;
vector<vector<int>> time;
queue<pair<int, int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs()
{
  int cnt = 0;

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      if (box[i][j] == 1)
      {
        q.push({i, j});
        time[i][j] = 0;
      }

  while (!q.empty())
  {
    auto ripen = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = dx[i] + ripen.first;
      int ny = dy[i] + ripen.second;

      if (nx < 0 || nx >= M || ny < 0 || ny >= N || box[nx][ny] == 1 || box[nx][ny] == -1)
        continue;

      box[nx][ny] = 1;
      time[nx][ny] = time[ripen.first][ripen.second] + 1;
      q.push({nx, ny});
    }
  }

  for (vector<int> row : box)
    for (int tomato : row)
      if (tomato == 0)
        return -1;

  for (vector<int> row : time)
    for (int spend : row)
      if (spend > cnt)
        cnt = spend;

  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  box.resize(M, vector<int>(N, -1));
  time.resize(M, vector<int>(N, -1));

  for (vector<int> &row : box)
    for (int &tomato : row)
      cin >> tomato;

  cout << bfs();

  return 0;
}
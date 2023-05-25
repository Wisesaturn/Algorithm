#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N, M;
int cnt = 0, biggest_Size = 0;
vector<vector<int>> paint;
unordered_map<int, unordered_map<int, bool>> visited;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int x, int y)
{
  int current_size = 1;
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] || paint[nx][ny] == 0)
        continue;

      visited[nx][ny] = true;
      current_size++;
      q.push({nx, ny});
    }
  }

  return current_size;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;
  paint.resize(N, vector<int>(M, 0));

  for (vector<int> &row : paint)
    for (int &point : row)
      cin >> point;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (paint[i][j] == 1 && !visited[i][j])
      {
        int curSize = bfs(i, j);
        cnt++;

        if (curSize > biggest_Size)
          biggest_Size = curSize;
      }
    }
  }

  cout << cnt << "\n";
  cout << biggest_Size;

  return 0;
}
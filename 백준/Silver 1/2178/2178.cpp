#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> maps;
vector<vector<int>> paths;
vector<vector<bool>> visited;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;

int bfs()
{
  queue<pair<int, int>> q;
  q.push({0, 0});
  paths[0][0] = 1;

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    if (cur.first == N - 1 && cur.second == M - 1)
      return paths[cur.first][cur.second];

    for (int i = 0; i < 4; i++)
    {
      int nx = dx[i] + cur.first;
      int ny = dy[i] + cur.second;

      if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1 || maps[nx][ny] == 0 || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      paths[nx][ny] = paths[cur.first][cur.second] + 1;
      q.push({nx, ny});
    }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  maps.resize(N, vector<int>(M, -1));
  paths.resize(N, vector<int>(M, 0));
  visited.resize(N, vector<bool>(M, false));

  vector<string> input;

  for (int k = 0; k < N; k++)
  {
    string tmp;
    cin >> tmp;
    input.push_back(tmp);
  }

  for (int i = 0; i < input.size(); i++)
    for (int j = 0; j < input[i].size(); j++)
      maps[i][j] = input[i][j] - '0';

  cout << bfs();

  return 0;
}
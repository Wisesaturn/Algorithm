#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> maps;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
vector<int> houses;

pair<int, int> d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs()
{
  int cnt = 1;

  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();

    for (pair<int, int> next : d)
    {
      int nx = cur.first + next.first;
      int ny = cur.second + next.second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= N || maps[nx][ny] == 0 || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
      cnt++;
    }
  }

  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  maps.resize(N, vector<int>(N, 0));
  visited.resize(N, vector<bool>(N, false));

  for (int i = 0; i < N; i++)
  {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < N; j++)
      maps[i][j] = tmp[j] - 48;
  }

  for (int i = 0; i < maps.size(); i++)
    for (int j = 0; j < maps[i].size(); j++)
      if (maps[i][j] == 1 && !visited[i][j])
      {
        q.push({i, j});
        visited[i][j] = true;
        houses.push_back(bfs());
      }

  sort(houses.begin(), houses.end());
  cout << houses.size() << "\n";
  for (int house : houses)
    cout << house << "\n";

  return 0;
}
#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int N, M;
vector<string> maps;
vector<vector<pair<int, int>>> parents;
map<char, pair<int, int>> direction;

pair<int, int> find(int x, int y)
{
  if (parents[x][y].first == x && parents[x][y].second == y)
    return make_pair(x, y);
  return parents[x][y] = find(parents[x][y].first, parents[x][y].second);
}

bool Union(const auto coord1, const auto coord2)
{
  auto p1 = find(coord1.first, coord1.second);
  auto p2 = find(coord2.first, coord2.second);

  if (p1 == p2)
    return false;
  return true;
}

int check()
{
  int cnt = 0;

  // find the path and parent
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      auto next = direction[maps[i - 1][j - 1]];
      auto parent = parents[i][j];
      int nx = next.first;
      int ny = next.second;
      auto nextCoord = make_pair(nx + parent.first, ny + parent.second);

      // interrupt the cycle
      if (Union(parents[i][j], nextCoord))
        parents[i][j] = make_pair(nx + parent.first, ny + parent.second);
    }
  }

  // check the escape
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      auto destination = find(i, j);
      int ex = destination.first;
      int ey = destination.second;

      if (ex > N || ex <= 0 || ey > M || ey <= 0)
        cnt++;
    }
  }

  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  direction['U'] = {-1, 0};
  direction['D'] = {1, 0};
  direction['L'] = {0, -1};
  direction['R'] = {0, 1};

  parents.resize(N + 2, vector<pair<int, int>>(M + 2));

  for (int i = 0; i <= N + 1; i++)
    for (int j = 0; j <= M + 1; j++)
      parents[i][j] = make_pair(i, j);

  for (int i = 0; i < N; i++)
  {
    string tmp = "";
    cin >> tmp;
    maps.push_back(tmp.substr(0, M));
  }

  cout << check();

  return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<unordered_map<int, bool>> visited;
vector<vector<int>> map;
vector<vector<int>> copyMap;
vector<pair<int, int>> viruses;

int N, M, ans = 0;

pair<int, int> d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs()
{
  int cnt = 0, isEmpty = 0;
  queue<pair<int, int>> q;

  copy(map.begin(), map.end(), copyMap.begin());

  for (auto virus : viruses)
  {
    q.push(virus);
    cnt++;
  }

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (auto direction : d)
    {
      int nx = direction.first + cur.first;
      int ny = direction.second + cur.second;

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || copyMap[nx][ny] != 0)
        continue;

      copyMap[nx][ny] = 2;
      cnt++;
      q.push({nx, ny});
    }
  }

  for (vector<int> row : copyMap)
    for (int element : row)
      if (element == 0)
        isEmpty++;

  if (ans < isEmpty)
  {
    ans = isEmpty;
    // cout << "--------------------------------" << endl;
    // for (auto row : copyMap)
    // {
    //   for (int e : row)
    //     cout << e << " ";
    //   cout << endl;
    // }
  }
}

void setWalls(int cnt)
{
  if (cnt == 3)
  {
    bfs();
    return;
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == 0)
      {
        map[i][j] = 1;
        setWalls(cnt + 1);
        map[i][j] = 0;
      }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  map.resize(N, vector<int>(M));
  copyMap.resize(N, vector<int>(M));

  for (vector<int> &row : map)
    for (int &e : row)
      cin >> e;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (map[i][j] == 2)
        viruses.push_back({i, j});

  setWalls(0);

  cout << ans;

  return 0;
}

// 2시간 이상
// bfs 유추하고, visited 여부를 따라서 queue에 push 해야 한다는 건 알았는데
// 아예 bfs 하나로 쭈욱 while문으로 도는 것보단
// 벽이 3개 생겼을 때 bfs를 해서 갯수를 체크하고
// 벽을 생기는 기능을 따로 두는게 훨씬 편했다.
// 이 기능을 하나로 묶고, struct를 사용하여 Point마다 값을 두어서 하기엔 메모리 감당도 안되고
// 너무 복잡하게 구현된다. (( 기능을 꼭 구분하자 ))
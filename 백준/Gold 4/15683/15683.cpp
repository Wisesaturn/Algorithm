#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<int, unordered_map<int, bool>> visited;
vector<vector<int>> map;
vector<vector<int>> camera;
vector<pair<int, int>> cameraCoord;
int N, M, maxCount = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void debug()
{
  cout << "==========" << endl;
  for (auto cam : camera)
  {
    for (auto c : cam)
      cout << c << " ";
    cout << endl;
  }
}

// direction : 북, 동, 서, 남
void check(int x, int y, int direction)
{
  int dir = direction % 4;
  while (x < N && y < M && x >= 0 && y >= 0)
  {
    x += dx[dir];
    y += dy[dir];
    if (x < 0 || y < 0 || x >= N || y >= M)
      break;

      // 카메라가 갈 수 있는 길이라면 카메라 길로 표시
      // (카메라 있어도 표시 - 상관 X)
    if (map[x][y] > 0 && map[x][y] < 6)
      camera[x][y] = 0;
    else if (map[x][y] == 0)
      camera[x][y] = 1;
      // 벽을 만날 때 종료
    if (map[x][y] == 6)
      break;
  }
}

void rollback(vector<vector<int>> &_camera)
{
  copy(_camera.begin(), _camera.end(), camera.begin());
}

void savePoint(vector<vector<int>> &_camera)
{
  copy(camera.begin(), camera.end(), _camera.begin());
}

void dfs(int depth)
{
  if (cameraCoord.size() == 0)
    return;

  int cx = cameraCoord[depth].first;
  int cy = cameraCoord[depth].second;

  // 3-1. camera depth를 채우면 최솟값 체크
  if (depth == cameraCoord.size())
  {
    int cnt = 0;
    for (int i = 0; i < camera.size(); i++)
      for (int j = 0; j < camera[i].size(); j++)
      // 카메라 길이거나, 카메라가 갈 수 없는 곳일 때 count
        if (camera[i][j] == 1 || camera[i][j] == 0)
          cnt++;
    if (cnt > maxCount)
    {
      // debug();
      maxCount = cnt;
    }

    return;
  }

  for (int dir = 0; dir < 4; dir++)
  {
    vector<vector<int>> _camera(N, vector<int>(M, 7));
    savePoint(_camera);
    switch (map[cx][cy])
    {
    case 1:
      check(cx, cy, dir);
      break;
    case 2:
    {
      check(cx, cy, dir);
      check(cx, cy, dir + 2);
      break;
    }
    case 3:
    {
      check(cx, cy, dir);
      check(cx, cy, dir + 1);
      break;
    }
    case 4:
    {
      check(cx, cy, dir);
      check(cx, cy, dir + 1);
      check(cx, cy, dir + 2);
      break;
    }
    case 5:
    {
      check(cx, cy, dir);
      check(cx, cy, dir + 1);
      check(cx, cy, dir + 2);
      check(cx, cy, dir + 3);
      break;
    }
    default:
      break;
    }

    dfs(depth + 1);
    rollback(_camera);
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 0. settings
  cin >> N >> M;
  map.resize(N, vector<int>(M, 0));
  // camera : 1이면 카메라 길, 0이면 카메라 길 X, 7면 없음
  camera.resize(N, vector<int>(M, 7));

  for (vector<int> &v : map)
    for (int &room : v)
      cin >> room;

  // 1. 벽과 카메라 위치 먼저 체크
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      // 벽 체크
      if (map[i][j] == 6)
      {
        camera[i][j] = 0;
        // 카운트 할 수 없는 영역이므로 +
        maxCount++;
      }
      // 카메라 체크
      else if (map[i][j] > 0 && map[i][j] < 6)
      {
        cameraCoord.push_back({i, j});
        camera[i][j] = 0;
      }

  // 2. 카메라 위치대로 경계 체크하기
  dfs(0);

  // 3. 출력 (전체 칸에서 카메라가 도달할 수 없는 영역 빼기)
  cout << (N * M) - maxCount;

  return 0;
}
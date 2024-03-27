#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

struct Point
{
  int x, y;
  Point(int X, int Y) : x(X), y(Y){};
};

struct Square
{
  Point s;
  Point t;
  int step;
  Square(Point S, Point T, int D) : s(S), t(T), step(D){};
};

vector<vector<int>> map;
int H, W, Sr, Sc, Fr, Fc;
int N, M, ans = 0;
unordered_map<int, unordered_map<int, bool>> visited;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(Square start)
{
  queue<Square> q;
  q.push(start);
  visited[start.s.x][start.s.y] = true;

  while (!q.empty())
  {
    auto curBox = q.front();
    Point cur = curBox.s;
    Point maxCur = curBox.t;
    q.pop();

    // cout << "cur : " << cur.x << " " << cur.y << " " << maxCur.x << " " << maxCur.y << endl;

    // 멈추는 조건
    if (cur.x == Fr && cur.y == Fc)
      return curBox.step;

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      int maxNx = maxCur.x + dx[i];
      int maxNy = maxCur.y + dy[i];

      // cout << "nextCur : " << nx << " " << ny << " " << maxNx << " " << maxNy << endl;

      // 기본 조건 체크
      if (visited[nx][ny] || nx < 0 || ny < 0 || maxNx >= N || maxNy >= M)
        continue;

      // cout << "1st" << endl;
      bool isBlocked = false;

      // 벽에 걸릴 때 체크
      if (dx[i] == -1)
      {
        // 상
        // cout << "top" << endl;
        for (int i = cur.y; i <= maxCur.y; i++)
          if (map[nx][i] == 1)
          {
            isBlocked = true;
            break;
          }
      }
      else if (dx[i] == 1)
      {
        // 하
        // cout << "bottom" << endl;
        for (int i = cur.y; i <= maxCur.y; i++)
        {
          if (map[maxNx][i] == 1)
          {
            isBlocked = true;
            break;
          }
        }
      }
      else if (dy[i] == -1)
      {
        // 좌
        // cout << "left" << endl;
        for (int i = cur.x; i <= maxCur.x; i++)
          if (map[i][ny] == 1)
          {
            isBlocked = true;
            break;
          }
      }
      else if (dy[i] == 1)
      {
        // 우
        // cout << "right" << endl;
        for (int i = cur.x; i <= maxCur.x; i++)
        {
          if (map[i][maxNy] == 1)
          {
            isBlocked = true;
            break;
          }
        }
      }

      if (isBlocked)
        continue;

      // cout << "good : " << nx << " " << ny << " " << maxNx << " " << maxNy << endl;

      visited[nx][ny] = true;
      q.push(Square(Point(nx, ny), Point(maxNx, maxNy), curBox.step + 1));
    }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 0. settings
  cin >> N >> M;
  map.resize(N, vector<int>(M));

  for (auto &row : map)
    for (int &item : row)
      cin >> item;

  cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

  // 0-2. 위치조정 (1,1 ~ M,N -> 0,0 ~ M-1,N-1)
  --H;
  --W;
  --Sr;
  --Sc;
  --Fr;
  --Fc;

  cout << bfs(Square(Point(Sr, Sc), Point(Sr + H, Sc + W), 0));

  return 0;
}

// 이동할 때 이동 방향의 직사각형 변과 맞닿는 부분이 벽이 아니어야 함
// 1h 10m
// 논리는 쉬운데 자꾸 좌표가 영역 밖으로 넘어가는 부분이 혼동이 되서 시간 딜레이됨
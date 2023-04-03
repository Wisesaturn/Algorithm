#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
int ans = 0, d = 0;
int N, M, K;

struct Dice
{
  int top = 1;
  int right = 3;
  int front = 5;
};

struct Point
{
  int x;
  int y;

  Point(int X, int Y) : x(X), y(Y){};
};

Point cur(0, 0);

Dice dice;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int check)
{
  int cnt = 1;

  queue<Point> q;
  q.push(cur);

  while (!q.empty())
  {
    Point cur = q.front();
    q.pop();
    visited[cur.x][cur.y] = true;

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] != check || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push(Point(nx, ny));
      cnt++;
    }
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      visited[i][j] = false;

  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M >> K;

  map.resize(N, vector<int>(M));
  visited.resize(N, vector<bool>(M, false));

  for (vector<int> &row : map)
    for (int &score : row)
      cin >> score;

  while (K--)
  {
    // 주사위 방향 움직이기
    if (cur.x + dx[d] < 0 || cur.x + dx[d] >= N || cur.y + dy[d] < 0 || cur.y + dy[d] >= M)
      d = (d + 2) % 4;

    cur.x += dx[d];
    cur.y += dy[d];

    // 주사위 굴리기
    int tmp = dice.top;
    switch (d)
    {
    case 0:
      dice.top = 7 - dice.right;
      dice.right = tmp;
      break;
    case 1:
      dice.top = 7 - dice.front;
      dice.front = tmp;
      break;
    case 2:
      dice.top = dice.right;
      dice.right = 7 - tmp;
      break;
    case 3:
      dice.top = dice.front;
      dice.front = 7 - tmp;
      break;
    default:
      break;
    }

    // 크기 체크 (A와 B)
    int A = 7 - dice.top;
    int B = map[cur.x][cur.y];

    // 크기에 따라 주사위 방향 바꾸기
    if (A > B)
      d = (d + 1) % 4;
    else if (A < B)
      d = (d - 1) < 0 ? 3 : (d - 1) % 4;

    // 점수 계산 ( B * C ( C = 밑 발판이 얼마나 같은 숫자로 연결되어 있는가?))
    int C = bfs(B);
    ans += (B * C);
  }

  cout << ans;

  return 0;
}

// 소요 시간 : 1시간 5분
// 문제 구현 난이도는 간단했는데 사소한 범위 오차나, 계산했을 때 잘못 나오는 식들에서 시간을 뺏겼다.
// 확실히 구현 문제는 메모를 미리 해두고 (수도 코드를 만들고) 짜는게 훨씬 편하다
// 시간을 좀 줄여볼 필요성이 있다. (1시간 이내로 최대한)
// 주사위는 세 면만 알아도 반대편을 알 수 있다는 상식만 알면 쉽게 풀 수 있었다
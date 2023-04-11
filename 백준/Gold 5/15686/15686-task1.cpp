#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, ans = 0, check = 0;
vector<vector<int>> map;
// 0 : 빈 칸, 1 : 집, 2 : 치킨 집
unordered_map<int, unordered_map<int, bool>> visited;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Point
{
  int x;
  int y;
  int length;

  Point(int X, int Y, int L) : x(X), y(Y), length(L){};
};

struct Chicken
{
  int max;
  int len;
  int x;
  int y;
  Chicken(int m, int l, int X, int Y) : max(m), len(l), x(X), y(Y){};
};

bool compare(const Chicken &c1, const Chicken &c2)
{
  if (c1.max == c2.max)
    return c1.len < c2.len;
  return c1.max < c2.max;
}

vector<Chicken> pq;

void bfs(Point start, bool checked)
{
  queue<Point> q;
  q.push(start);

  Chicken chicken(0, 0, start.x, start.y);

  while (!q.empty())
  {
    Point cur = q.front();
    q.pop();

    if (checked == false)
    {
      // 최선의 치킨집을 파악 (max 길이가 가장 낮은 것)
      if (map[cur.x][cur.y] == 1)
      {
        chicken.len += cur.length;

        if (chicken.max < cur.length)
          chicken.max = cur.length;

        continue;
      }
    }
    else if (checked == true)
    {
      // 가장 가까운 치킨집을 만나면 length 더하기
      if (map[cur.x][cur.y] == 2)
      {
        ans += cur.length;
        break;
      }
    }

    for (int i = 0; i < 4; i++)
    {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny])
        continue;

      q.push(Point(nx, ny, cur.length + 1));
      visited[nx][ny] = true;
    }
  }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (visited[i][j])
        visited[i][j] = false;

  if (checked == false)
    pq.push_back(chicken);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  map.resize(N, vector<int>(N));

  for (vector<int> &row : map)
    for (int &house : row)
      cin >> house;

  // 우선 각 집 별로 최소한의 길이를 파악 (일단 가장 가까운 치킨집들을 찾아본다)
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == 1)
        bfs(Point(i, j, 0), true);

  // ans 초기화
  check = ans;
  ans = 0;

  // 각 치킨집 별로 최소한의 길이를 파악
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == 2)
        bfs(Point(i, j, 0), false);

  // pq vector 정렬
  sort(pq.begin(), pq.end(), compare);

  // M의 갯수에 따라 치킨집 폐업
  for (int i = M; i < pq.size(); i++)
    map[pq[i].x][pq[i].y] = 0;

  // 치킨집 폐업 후 각 집 별로 최소한의 길이를 다시 파악
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (map[i][j] == 1)
        bfs(Point(i, j, 0), true);

  // 결과 출력
  if (check < ans)
    cout << check;
  else
    cout << ans;

  // 디버깅
  // cout << "---------------" << endl;
  // for (int i = 0; i < N; i++)
  // {
  //   for (int j = 0; j < N; j++)
  //     cout << map[i][j] << " ";
  //   cout << endl;
  // }

  // cout << "---------------" << endl;

  for (int i = 0; i < pq.size(); i++)
  {
    cout << pq[i].x << " " << pq[i].y << " " << pq[i].len << " " << pq[i].max << endl;
  }

  return 0;
}

// 2시간 이상
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> cleaned;

struct point
{
  int x;
  int y;

  point(int r, int c) : x(r), y(c){};
};

point direction[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool checked(point current)
{
  for (auto next : direction)
  {
    int nx = current.x + next.x;
    int ny = current.y + next.y;

    if (cleaned[nx][ny] == 0 && map[nx][ny] == 0)
      return true;
  }

  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  int cnt = 0;
  cin >> N >> M;

  map.resize(N, vector<int>(M, 0));
  cleaned.resize(N, vector<int>(M, 0));

  int r, c, d;
  cin >> r >> c >> d;

  for (vector<int> &row : map)
    for (int &state : row)
      cin >> state;

  point robot(r, c);

  // 1. 맨 처음 청소
  cleaned[r][c] = 1;
  cnt++;

  // 2. 주변 탐색
  while (true)
  {
    if (checked(robot))
    {
      // 2-1. 청소되지 않은 빈 칸이 있을 경우
      d == 0 ? d = 3 : d--;

      if (cleaned[robot.x + direction[d].x][robot.y + direction[d].y] == 0 && map[robot.x + direction[d].x][robot.y + direction[d].y] == 0)
      {
        // cout << d << " " << robot.x << " " << robot.y << endl;
        robot.x += direction[d].x;
        robot.y += direction[d].y;
      }

      // 청소
      if (cleaned[robot.x][robot.y] == 1)
        continue;

      cleaned[robot.x][robot.y] = 1;
      cnt++;

      continue;
    }

    // 2-2. 청소되지 않은 빈 칸이 없을 경우
    if (map[robot.x - direction[d].x][robot.y - direction[d].y] == 0)
    {
      robot.x -= direction[d].x;
      robot.y -= direction[d].y;

      // 청소
      if (cleaned[robot.x][robot.y] == 1)
        continue;

      cleaned[robot.x][robot.y] = 1;
      cnt++;

      continue;
    }

    break;
  }

  // cout << "--------------------------------" << endl;

  // for (auto row : test)
  // {
  //   for (int e : row)
  //     cout << e << " ";
  //   cout << endl;
  // }

  // cout << robot.x << " " << robot.y << endl;

  cout << cnt;

  return 0;
}

// 1시간 소요
// 알고리즘 짠지는 30분만에 짠거 같은데 direction 값 때문에 30분을 낭비했다.
// 조금 더 꼼꼼하게 시뮬레이션을 돌려보자
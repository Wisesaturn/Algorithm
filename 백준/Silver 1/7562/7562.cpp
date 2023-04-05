#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

pair<int, int> direction[] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
unordered_map<int, unordered_map<int, bool>> visited;

void bfs(pair<int, int> start, pair<int, int> end, int length)
{
  int cnt = 0;
  queue<pair<int, pair<int, int>>> q;
  q.push({0, start});

  while (!q.empty())
  {
    auto cur = q.front();
    int count = cur.first;
    auto point = cur.second;
    q.pop();

    if (point.first == end.first && point.second == end.second)
    {
      cnt = count;
      break;
    }

    for (auto d : direction)
    {
      int nx = point.first + d.second;
      int ny = point.second + d.first;

      if (nx < 0 || ny < 0 || nx >= length || ny >= length || visited[nx][ny])
        continue;

      visited[nx][ny] = true;
      q.push({count + 1, {nx, ny}});
    }
  }

  for (int i = 0; i < length; i++)
    for (int j = 0; j < length; j++)
      if (visited[i][j])
        visited[i][j] = false;

  cout << cnt << "\n";
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T;
  cin >> T;

  while (T--)
  {
    int length;
    cin >> length;

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    bfs(start, end, length);
  }

  return 0;
}

// 30분 소요
// 역시 direction 값이 중복되서 10분을 헤맸다. 좀 더 침착하게 보자
// 은근 헷갈리는 건 (x + 1, y + 2)인 상황은 y칸을 +1, x칸을 +2 한다는 점이다
// 그래서 데카르트 좌표계로 dx, dy를 만든 다음 서로 이름만 바꾸면 쉽게 계산될 것 같다
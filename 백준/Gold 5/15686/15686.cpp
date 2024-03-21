#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

int N, M, ans = INT_MAX;

struct House
{
  int x;
  int y;
  House(int r, int c) : x(r), y(c){};
};

struct Chicken
{
  int x;
  int y;
  bool visited;
  Chicken(int r, int c, bool v) : x(r), y(c), visited(v) {}
};

vector<vector<int>> map;
vector<Chicken> chicken;
vector<House> house;

void calculateChicken()
{
  int dist = 0;
  for (auto h : house)
  {
    int minHouseDist = INT_MAX;
    for (auto c : chicken)
    {
      if (!c.visited)
        continue;

      int houseDist = abs(h.x - c.x) + abs(h.y - c.y);
      minHouseDist = min(houseDist, minHouseDist);
    }
    dist += minHouseDist;
  }

  ans = min(dist, ans);
}

void selectChicken(int pivot, int cnt)
{
  if (cnt == M)
  {
    calculateChicken();
    return;
  }

  for (int i = pivot; i < chicken.size(); i++)
  {
    if (chicken[i].visited)
      continue;

    chicken[i].visited = true;
    selectChicken(i, cnt + 1);
    chicken[i].visited = false;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;
  map.resize(N, vector<int>(N));

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int p;
      cin >> p;

      if (p == 1)
        house.emplace_back(i, j);
      else if (p == 2)
        chicken.emplace_back(i, j, false);
    }
  }

  selectChicken(0, 0);
  cout << ans;

  return 0;
}

// 하도 안 풀려서 참고
// https://velog.io/@dianestar/%EB%B0%B1%EC%A4%80BOJ-15686%EB%B2%88-%EC%B9%98%ED%82%A8%EB%B0%B0%EB%8B%AC
// 조합으로 치킨집을 고른 다음, min 값을 카운팅하는 방법
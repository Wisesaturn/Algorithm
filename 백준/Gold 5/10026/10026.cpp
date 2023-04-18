#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int N, row = 0;
int isNotWeak = 0, isWeak = 0;
vector<vector<char>> picture;
unordered_map<int, unordered_map<int, bool>> visitedWeak;
unordered_map<int, unordered_map<int, bool>> visitedNotWeak;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y)
{
  char mainChar = picture[x][y];
  queue<pair<bool, pair<int, int>>> q;

  if (!visitedWeak[x][y])
    q.push({true, {x, y}});
  if (!visitedNotWeak[x][y])
    q.push({false, {x, y}});

  visitedWeak[x][y] = true;
  visitedNotWeak[x][y] = true;

  while (!q.empty())
  {
    auto cur = q.front();
    auto point = cur.second;
    bool isWeaken = cur.first; // true : 적록색약 , false : 적록색약 X
    bool isChecked = false;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = point.first + dx[i];
      int ny = point.second + dy[i];

      // cout << isWeaken << " " << nx << " " << ny << endl;
      if (nx < 0 || ny < 0 || nx >= N || ny >= N)
        continue;

      if (isWeaken)
      {
        if (visitedWeak[nx][ny])
          continue;

        if (mainChar == 'R' || mainChar == 'G')
        {
          if (picture[nx][ny] == 'G' || picture[nx][ny] == 'R')
          {
            visitedWeak[nx][ny] = true;
            q.push({true, {nx, ny}});
          }
        }
        else
        {
          if (picture[nx][ny] == 'B')
          {
            visitedWeak[nx][ny] = true;
            q.push({true, {nx, ny}});
          }
        }
      }
      else
      {
        if (visitedNotWeak[nx][ny])
          continue;

        if (picture[nx][ny] == mainChar)
        {
          visitedNotWeak[nx][ny] = true;
          q.push({false, {nx, ny}});
        }
      }
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  picture.resize(N, vector<char>(N));

  for (vector<char> &line : picture)
    for (char &ch : line)
      cin >> ch;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (!visitedNotWeak[i][j] || !visitedWeak[i][j])
      {
        if (!visitedNotWeak[i][j])
          isNotWeak++;
        if (!visitedWeak[i][j])
          isWeak++;

        bfs(i, j);
      }
    }
  }
  // for (int i = 1; i <= N; i++)
  // {
  //   for (int j = 0; j < N; j++)
  //   {
  //     cout << visitedWeak[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << isNotWeak << " " << isWeak;

  return 0;
}

// 1시간 30분 소요
// 문제 푼건 1시간 걸렸는데 왜 그런진 모르겠지만 visited를 바꿔주니깐 일단 해결은 됐다.
// vector<string> 보단 vector<vector<char>>를 애용하자
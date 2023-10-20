#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct location
{
  int x;
  int y;
  bool turnOnLever = false;

  location(int X, int Y, bool turnOn) : x(X), y(Y), turnOnLever(turnOn){};
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int col = 0;
int row = 0;
bool isTurnOn = false;
vector<vector<int>> visited;
vector<vector<int>> hadToWay;

void visitEmpty()
{
  for (int i = 0; i < col; i++)
  {
    for (int j = 0; j < row; j++)
    {
      hadToWay[i][j] = 0;
    }
  }
}

int bfs(location locate, vector<string> &maps)
{
  int ans = -1;
  queue<location> q;
  q.push(locate);

  visited[locate.x][locate.y] = 0;
  hadToWay[locate.x][locate.y] = 1;

  while (!q.empty())
  {
    location cur = q.front();
    q.pop();

    if (!cur.turnOnLever && maps[cur.x][cur.y] == 'L')
    {
      cur.turnOnLever = true;
      isTurnOn = true;
      visitEmpty();
    }

    if (cur.turnOnLever && maps[cur.x][cur.y] == 'E')
    {
      ans = visited[cur.x][cur.y];
      break;
    }

    for (int k = 0; k < 4; k++)
    {
      int nx = cur.x + dx[k];
      int ny = cur.y + dy[k];

      if (nx < 0 || ny < 0 || nx >= col || ny >= row || hadToWay[nx][ny] == 1 || maps[nx][ny] == 'X')
        continue;

      if (isTurnOn && !cur.turnOnLever)
        continue;

      q.push({nx, ny, cur.turnOnLever});
      visited[nx][ny] = visited[cur.x][cur.y] + 1;
      hadToWay[nx][ny] = 1;
    }
  }

  for (int i = 0; i < maps.size(); i++)
  {
    for (int j = 0; j < maps[i].size(); j++)
    {
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }

  return ans;
}

int solution(vector<string> maps)
{
  location start = {0, 0, false};
  location end = {0, 0, false};
  location lever = {0, 0, false};
  col = maps.size();
  row = maps[0].size();
  visited.resize(col, vector<int>(row, 0));
  hadToWay.resize(col, vector<int>(row, 0));

  for (int i = 0; i < maps.size(); i++)
  {
    for (int j = 0; j < maps[i].size(); j++)
    {
      char info = maps[i][j];
      if (info == 'S')
      {
        start = {i, j, false};
      }
      else if (info == 'L')
      {
        lever = {i, j, false};
      }
      else if (info == 'E')
      {
        end = {i, j, false};
      }
    }
  }

  return bfs(start, maps);
}
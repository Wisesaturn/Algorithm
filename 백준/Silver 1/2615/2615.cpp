#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> maps(19, vector<int>(19, 0));
vector<vector<int>> dp(19, vector<int>(19, 0));
int winner = -1;
pair<int, int> winnerCoords;

pair<int, int> direction[] = {{0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};

void clean()
{
  for (vector<int> &rows : dp)
    for (int &stone : rows)
      stone = 0;
}

void check()
{
  for (int k = 0; k < 4; k++)
  {
    // 이전 방향의 좌표 확인
    int bx = direction[k].first;
    int by = direction[k].second;

    for (int i = 0; i < 19; i++)
    {
      for (int j = 0; j < 19; j++)
      {
        // 돌이 없으면 넘김
        if (maps[i][j] == 0)
          continue;

        // 돌이 있으면 일단 채우고
        dp[i][j] = 1;

        // 이전 방향의 좌표가 밖을 넘어가면 넘김
        if (i + bx < 0 || i + bx >= 19 || j + by < 0 || j + by >= 19)
          continue;

        // 이전 방향의 좌표가 돌이 같다면, 현재 좌표 값을 + 1
        if (maps[i][j] == maps[i + bx][j + by])
          dp[i][j] = dp[i + bx][j + by] + 1;

        // 이 때 5개가 채워졌을 때, 그 다음 위치가 판 밖이라면
        if (dp[i][j] == 5 && (i - bx < 0 || i - bx >= 19 || j - by < 0 || j - by >= 19))
        {
          winner = maps[i][j];
          // 오른쪽 대각선 방향일 때만 따로 조건 부여
          if (k == 3)
          {
            winnerCoords.first = i + 1;
            winnerCoords.second = j + 1;
          }
          // 나머지
          else
          {
            winnerCoords.first = i + (bx * 4) + 1;
            winnerCoords.second = j + (by * 4) + 1;
          }

          return;
        }

        // 이 때 5개가 채워졌을 때, 다음 돌이 연속되지 않았다면 (즉, 육목이 아니라면)
        if (dp[i][j] == 5 && maps[i - bx][j - by] != maps[i][j])
        {
          winner = maps[i][j];
          // 오른쪽 대각선 방향일 때만 따로 조건 부여
          if (k == 3)
          {
            winnerCoords.first = i + 1;
            winnerCoords.second = j + 1;
          }
          // 나머지
          else
          {
            winnerCoords.first = i + (bx * 4) + 1;
            winnerCoords.second = j + (by * 4) + 1;
          }

          return;
        }
      }
    }

    clean();
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  for (vector<int> &rows : maps)
    for (int &stone : rows)
      cin >> stone;

  check();

  // cout << "\n----------------------------------------------------------------" << endl;

  // for (vector<int> rows : dp)
  // {
  //   for (int stone : rows)
  //     cout << stone << " ";
  //   cout << endl;
  // }

  winner == -1 ? cout << 0 : cout << winner;
  cout << "\n";

  if (winner > -1)
    cout << winnerCoords.first << " " << winnerCoords.second << "\n";

  return 0;
}
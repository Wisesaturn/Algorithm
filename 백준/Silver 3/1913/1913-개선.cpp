#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M, cnt = 1;
  cin >> N >> M;

  vector<vector<int>> arr(N, vector<int>(N));
  pair<int, int> cur = {N / 2, N / 2};
  pair<int, int> pos;
  // 0. 시작
  arr[cur.first][cur.second] = cnt;

  for (int i = 0; i < N / 2; i++)
  {
    int dcnt = -1;
    // 1. 윗칸
    arr[--cur.first][cur.second] = ++cnt;
    // 2. 테두리
    while (dcnt++, dcnt < 4)
      switch (dcnt)
      {
      case 0:
        for (int j = 0; j < 2 * i + 1; j++)
          arr[cur.first][++cur.second] = ++cnt;
        break;
      case 1:
        for (int j = 0; j < 2 * i + 2; j++)
          arr[++cur.first][cur.second] = ++cnt;
        break;
      case 2:
        for (int j = 0; j < 2 * i + 2; j++)
          arr[cur.first][--cur.second] = ++cnt;
        break;
      case 3:
        for (int j = 0; j < 2 * i + 2; j++)
          arr[--cur.first][cur.second] = ++cnt;
        break;
      }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << arr[i][j] << " ";
      if (arr[i][j] == M)
        pos = {i, j};
    }
    cout << "\n";
  }

  cout << ++pos.first << " " << ++pos.second;

  return 0;
}
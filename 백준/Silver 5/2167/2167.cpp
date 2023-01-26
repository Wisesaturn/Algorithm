#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> arr(N, vector<int>(M));
  for (vector<int> &i : arr)
    for (int &j : i)
      cin >> j;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
    {
      if (i == 0 && j == 0)
        continue;

      if (i == 0)
      {
        arr[0][j] += arr[0][j - 1];
        continue;
      }
      else if (j == 0)
      {
        arr[i][0] += arr[i - 1][0];
        continue;
      }

      arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }

  int K;
  cin >> K;

  while (K--)
  {
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    if (sy == 1 && sx == 1)
      cout << arr[dx - 1][dy - 1] << "\n";
    else if (sx == 1 && sy > 1)
      cout << arr[dx - 1][dy - 1] - arr[dx - 1][sy - 2] << "\n";
    else if (sy == 1 && sx > 1)
      cout << arr[dx - 1][dy - 1] - arr[sx - 2][dy - 1] << "\n";
    else
      cout << arr[dx - 1][dy - 1] - arr[dx - 1][sy - 2] - arr[sx - 2][dy - 1] + arr[sx - 2][sy - 2] << "\n";
  }

  return 0;
}
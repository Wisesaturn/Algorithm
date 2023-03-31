#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // index 2 : right, index 6 : left
  string gears[4];
  int rotation[4] = {0, 0, 0, 0};

  for (string &gear : gears)
    getline(cin, gear);

  int K;
  cin >> K;

  while (K--)
  {
    int n, r;
    cin >> n >> r;

    rotation[n - 1] = r;

    char centerLeft = gears[n - 1][6];
    char centerRight = gears[n - 1][2];

    // 회전 여부 파악
    // 1단계 : 선택된 기어를 중심으로 양 옆 파악
    if (n - 2 >= 0 && centerLeft != gears[n - 2][2])
      rotation[n - 2] = -r;

    if (n < 4 && centerRight != gears[n][6])
      rotation[n] = -r;

    // 2단계 : 나머지 기어 파악
    for (int i = 0; i < 4; i++)
    {
      if (rotation[i] != 0)
        continue;

      if (i + 1 >= 0 && i + 1 < 4 && gears[i + 1][6] != gears[i][2] && rotation[i + 1] != 0)
      {
        rotation[i] = -rotation[i + 1];
        continue;
      }
      else if (i - 1 >= 0 && i - 1 < 4 && gears[i - 1][2] != gears[i][6] && rotation[i - 1] != 0)
        rotation[i] = -rotation[i - 1];
    }
    // 추가 경우
    if (n == 4)
      if (rotation[1] != 0 && gears[1][6] != gears[0][2])
        rotation[0] = -rotation[1];

    // 행동 출력
    for (int i = 0; i < 4; i++)
    {
      if (rotation[i] == 0)
        continue;

      if (rotation[i] == 1)
      {
        string tmp = gears[i].substr(0, 7);
        char first = gears[i][7];
        gears[i] = first + tmp;
      }
      else if (rotation[i] == -1)
      {
        string tmp = gears[i].substr(1, 8);
        char last = gears[i][0];
        gears[i] = tmp + last;
      }
    }

    // for (string s : gears)
    //   cout << s << endl;
    // cout << "--------------------------------" << endl;

    // rotation stack 초기화
    for (int i = 0; i < 4; i++)
      rotation[i] = 0;
  }

  int ans = 0;

  for (int i = 0; i < 4; i++)
    if (gears[i][0] == '1')
      ans += pow(2, i);

  cout << ans;

  return 0;
}

// 1시간 10분
// 졸려서 약간 더디긴 했는데 쉬운 구현 문제였다.
// 추가 경우가 for문에서 top-down 방식으로 오면 첫번째 기어는 rotation 체크를 못하여서
// 어떻게 더 깔끔하게 짤까 고민하다가 그냥 조건문으로 대입했다.
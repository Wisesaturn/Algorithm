#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, coin = 0;

  cin >> N;
  vector<int> list(N);

  for (int &ramen : list)
    cin >> ramen;

  // 마지막 체크 고려
  list.push_back(0);
  list.push_back(0);

  for (int i = 0; i < N; i++)
  {
    if (list[i] == 0)
      continue;

    if (list[i] > 0 && list[i + 1] > 0 && list[i + 2] > 0)
    {
      // 3개 없애기
      // 1. i+1 <= i+2
      if (list[i + 1] <= list[i + 2])
      {
        int tmp = min(list[i], min(list[i + 1], list[i + 2]));
        list[i] -= tmp;
        list[i + 1] -= tmp;
        list[i + 2] -= tmp;
        coin += 7 * tmp;
        // cout << "first " << coin << endl;
      }
      else
      {
        // 2. i+1 > i+2
        int tmp = min(list[i], list[i + 1] - list[i + 2]);
        list[i] -= tmp;
        list[i + 1] -= tmp;
        coin += 5 * tmp;
        // cout << "second " << coin << endl;

        tmp = min(list[i], min(list[i + 1], list[i + 2]));
        list[i] -= tmp;
        list[i + 1] -= tmp;
        list[i + 2] -= tmp;
        coin += 7 * tmp;
      }
    }

    // i번째가 아직 남아있다면
    while (list[i] > 0)
    {
      if (list[i + 1] > 0)
      {
        int tmp = min(list[i + 1], list[i]);
        coin += 5 * tmp;
        list[i + 1] -= tmp;
        list[i] -= tmp;
        // cout << "fourth " << coin << endl;
      }
      else
      {
        coin += 3 * list[i];
        list[i] = 0;
        // cout << "fifth " << coin << endl;
      }
    }
  }

  cout << coin;

  return 0;
}

// 2시간 이상 소요
// 1. 해당 index에서 3군데 라면을 살 수 있다면 두 가지 경우의 수로 나누어보자
// i + 1 <= i + 2
// ex) 1 2 3 -> 0 1 2
// ex) 3 2 3 -> 1 0 1
// ex) 2 2 3 -> 0 0 1
// 어떤 경우가 나오든, i + 2가 크다면 가장 작은 값은 i 또는 i + 1
// i + 1이 제일 작을 경우, i 혼자 동 떨어지지만 이런 경우일 수밖에 없다.
// i가 제일 작을 경우, i + 1과 i + 2이 이어져 다음 조합을 만들 수 있다.

// 결론) 이 3개 중 가장 작은 수를 찾고 이 수에 따라 3개짜리 라면값을 계산한다.
// 만약, i번째에 값이 남아있을 경우 i + 1 을 고려하여 2개 혹은 1개짜리 라면값을 계산한다.
// i를 무조건 0으로 만들 때까지 계산한다.

// i + 1 > i + 2
// ex) 1 4 3 -> 0 3 2
// ex) 3 4 3 -> 0 1 0
// ex) 6 4 3 -> 3 1 0
// 여기서 중요한 점
// -> 가운데를 남기지 않고 다음 인덱스와 연결짓도록 만들자
// -> 먼저 i와 i번째를 계산하는데 i + 1 == i + 2가 될 때까지 계산한다.
// -> i + 1과 i - 2의 차이보다 i가 작다면, i의 인덱스를 기준으로 계산하고 다음으로 넘어간다.
//-> 만약 i + 1과 i - 2의 차이가 i보다 더 작다면, i + 1 == i == 2를 만들고 다음으로 넘어간다.
// 그 다음 똑같이 3개의 인덱스 중 가장 작은 값을 찾고 3개짜리 라면값을 계산한다.
// i가 남았을 경우 역시 남은 값을 고려하여 2개 혹은 1개짜리 라면값을 계산한다.

// 반례찾기가 많이 빡셌다.
// 반례 들어서 확인했던 것들
// 4
// 2 3 2 1
// 5
// 2 3 2 1 1
// 4
// 1 2 3 4
// 4
// 1 2 2 1
// 4
// 1 2 1 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long N;
  cin >> N;

  vector<pair<long long, long long>> data(N);
  vector<long long> dp(N + 1, 0);

  for (long long i = 0; i < N; i++)
  {
    long long T, P;
    cin >> T >> P;
    data[i] = make_pair(T, P);
  }

  for (long long j = N - 1; j >= 0; j--)
  {
    if (data[j].first + j > N)
      dp[j] = dp[j + 1];
    else
      dp[j] = max(data[j].second + dp[j + data[j].first], dp[j + 1]);
  }

  cout << dp[0];

  return 0;
}

// 시간 초과 / 메모리 초과 오답
// int main(int argc, char *argv[])
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL), cout.tie(NULL);

//   long long N;
//   cin >> N;

//   vector<pair<long long, long long>> data(N);
//   vector<long long> dp(N, 0);

//   for (long long i = 0; i < N; i++)
//   {
//     long long T, P;
//     cin >> T >> P;
//     data[i] = make_pair(T, P);
//   }

//   for (long long j = N - 1; j >= 0; j--)
//   {
//     if (data[j].first + j > N)
//       continue;
//    --> continue로 넘기는 것보단 이전 최댓값을 이어 받아야 한다 (상담하지 않았을 때 최댓값)

//     dp[j] = *max_element(&dp[j], &dp[N - 1]);
//    --> 의미가 없다 (어차피 dp는 최댓값을 찾으므로, dp[0]이 곧 입력값의 최댓값)

//     if (j == N - data[j].first)
//       dp[j] = max(data[j].second, dp[j]);
//    --> 맨 위 조건문에 의해 의미가 없는 조건문이다
//    --> 그리고 무조건 상담해야한다는 조건을 가진다
//     else
//       dp[j] = max(data[j].second + dp[j + data[j].first], dp[j]);
//    --> 이전값과 해당 날짜에 상담했을 때를 비교해야 한다
//   }

//   cout << *max_element(dp.begin(), dp.end());
//    --> dp[0]이 곧 최댓값, 의미가 없다

//   return 0;
// }
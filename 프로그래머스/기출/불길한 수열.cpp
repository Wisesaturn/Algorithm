#include <string>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n)
{
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  pq.push(4);
  pq.push(13);

  long long ans = 0;

  for (int i = 2; i <= n; ++i)
  {
    long long num = pq.top();

    pq.pop();

    pq.push(stoll(to_string(num) + "4"));
    pq.push(stoll(to_string(num) + "13"));
  }

  ans = pq.top();
  return ans;
}

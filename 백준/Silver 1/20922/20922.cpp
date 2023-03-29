#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, K;
vector<int> list(N);
unordered_map<int, int> visited;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int ans = 0;

  cin >> N >> K;

  list.resize(N);

  for (int &element : list)
    cin >> element;

  int start = 0;
  int end = 0;
  int cnt = 1;
  visited[list[0]] = 1;

  while (end < N)
  {
    if (visited[list[end]] > K)
    {
      if (ans < cnt - 1)
        ans = cnt - 1;

      do
      {
        visited[list[start]] -= 1;
        start++;
        cnt--;
      } while (visited[list[end]] > K);

      continue;
    }

    end++;
    cnt++;

    if (!visited[list[end]])
      visited[list[end]] = 1;
    else
      visited[list[end]] += 1;
  }

  if (ans < cnt - 1)
    ans = cnt - 1;

  cout << ans;
  return 0;
}

// 소요 : 80분
// 너무 많이 걸렸다
// 원인 - for문을 통해 visited 전체를 확인하려고 했다. Max로 잡으면 200000 * 100000번 소요되는데 이점을 간과했다.
// 그냥 다음 end 값이 기준에 못미치면 start를 땡기면 되는데 간단한 해법을 생각하지 못했다.
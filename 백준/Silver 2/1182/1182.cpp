#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, S, cnt = 0;
vector<int> list;
unordered_map<int, bool> visited;

void dfs(int sum, int cur)
{
  for (int i = cur; i < N; i++)
  {
    if (visited[i])
      continue;

    if (sum + list[i] == S)
      cnt++;

    visited[i] = true;
    dfs(sum + list[i], i + 1);
    visited[i] = false;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> S;

  list.resize(N);

  for (int &num : list)
    cin >> num;

  dfs(0, 0);

  cout << cnt;

  return 0;
}

// 16분 소요
// cnt하는 부분에서 continue;를 사용하여 멈춰버렸다.
// 그냥 넘어가서 dfs을 bruth-force처럼 다 돌아도 되는데 백트래킹을 너무 생각한 탓이었다
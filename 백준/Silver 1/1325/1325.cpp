#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M, maxNum = 0, cnt = 1;

bool visited[10001];
vector<int> graph[10001];
vector<pair<int, int>> computers;

void resetVisit()
{
  for (int i = 1; i <= N; i++)
    visited[i] = false;
}

void dfs(int n)
{
  visited[n] = true;

  for (auto node : graph[n])
  {
    if (visited[node] == 0)
    {
      visited[node] = true;
      dfs(node);
      cnt++;
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  while (M--)
  {
    int A, B;
    cin >> A >> B;
    graph[B].push_back(A);
  }

  for (int i = 1; i <= N; i++)
  {
    dfs(i);
    resetVisit();
    if (cnt > maxNum)
      maxNum = cnt;
    if (cnt > 0)
      computers.push_back({cnt, i});
    cnt = 1;
  }

  for (auto num : computers)
    if (num.first == maxNum)
      cout << num.second << " ";

  return 0;
}
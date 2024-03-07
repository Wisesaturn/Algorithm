#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, bool> visited;
unordered_map<int, bool> blocked;

void dfs(int node, const vector<vector<int>> &computers)
{
  vector<int> target = computers[node];

  for (int t = 0; t < target.size(); t++)
  {
    if (t == node)
      continue;

    if (visited[t] || target[t] == 0)
      continue;

    // cout << t << "(debug)" << endl;
    visited[t] = true;
    dfs(t, computers);
  }
}

int solution(int n, vector<vector<int>> computers)
{
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (visited[i])
      continue;

    dfs(i, computers);
    ans++;
  }

  return ans;
}
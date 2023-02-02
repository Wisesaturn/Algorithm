#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

vector<set<int>> v;
unordered_map<int, bool> visitedDFS;
unordered_map<int, bool> visitedBFS;

vector<int> dfs(int n)
{
  vector<int> ans;
  ans.push_back(n);
  visitedDFS[n] = true;

  for (int i : v[n])
  {
    if (!visitedDFS[i])
    {
      visitedDFS[i] = true;
      for (int j : dfs(i))
        ans.push_back(j);
    }
  }

  return ans;
}

vector<int> bfs(int n)
{
  queue<int> q;
  vector<int> ans;

  q.push(n);
  visitedBFS[n] = true;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    ans.push_back(cur);

    for (int i : v[cur])
    {
      if (visitedBFS[i])
        continue;
      q.push(i);
      visitedBFS[i] = true;
    }
  }

  return ans;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M, V;

  cin >> N >> M >> V;

  v.resize(N + 1, set<int>());

  while (M--)
  {
    int s, e;
    cin >> s >> e;

    v[s].insert(e);
    v[e].insert(s);
  }

  for (int i : dfs(V))
    cout << i << " ";

  cout << "\n";
  for (int j : bfs(V))
    cout << j << " ";

  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M, p1, p2;
vector<vector<int>> family;
unordered_map<int, bool> visited;

int dfs(int p1, int p2, int depth)
{
  int cnt = -1;
  if (p1 == p2)
    return depth + 1;

  for (int node : family[p1])
  {
    if (visited[node])
      continue;

    visited[node] = true;
    if (node == p2)
    {
      cnt = depth + 1;
      return cnt;
    }
    else
    {
      int tmp = dfs(node, p2, ++depth);
      if (cnt < tmp)
        cnt = tmp;
      --depth;
    }
    visited[node] = false;
  }

  return cnt == -1 ? -1 : cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  cin >> p1 >> p2;
  cin >> M;

  family.resize(N + 1, vector<int>());

  while (M--)
  {
    int parent, child;
    cin >> parent >> child;
    family[child].push_back(parent);
    family[parent].push_back(child);
  }

  visited[p1] = true;
  cout << dfs(p1, p2, 0);

  return 0;
}
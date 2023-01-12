#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt = 0;
vector<vector<int>> g;
vector<bool> v;

void dfs(int node)
{
  v[node] = true;

  for (int i = 0; i < N; i++)
    if (g[node][i] == 1 && v[i] == false)
      dfs(i);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  g.resize(N, vector<int>(N, 0));
  v.resize(N, false);

  while (M--)
  {
    int u, v;
    cin >> u >> v;

    g[u - 1][v - 1] = 1;
    g[v - 1][u - 1] = 1;
  }

  for (int i = 0; i < N; i++)
  {
    if (v[i] == true)
      continue;
    else
    {
      dfs(i);
      cnt++;
    }
  }

  cout << cnt;

  return 0;
}
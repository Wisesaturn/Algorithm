#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt = 0;
vector<vector<int>> g;
vector<bool> v;

void bfs(int node)
{
  queue<int> q;
  q.push(node);
  v[node] = true;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    for (int i = 0; i < N; i++)
    {
      if (g[cur][i] == 0 || v[i] == true)
        continue;

      q.push(i);
      v[i] = true;
    }
  }
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

    bfs(i);
    cnt++;
  }

  cout << cnt;

  return 0;
}
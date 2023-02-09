#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> paths;
vector<int> parent;
vector<int> lv;

int find(int u)
{
  if (parent[u] == u)
    return u;
  return parent[u] = find(parent[u]);
}

bool Union(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v)
    return false;

  if (lv[u] > lv[v])
    swap(u, v);

  parent[u] = v;

  if (lv[u] == lv[v])
    lv[v]++;

  return true;
}

int kruskal()
{
  int sum = 0, cnt = 0;

  for (int i = 0; i < paths.size(); i++)
  {
    if (cnt > N - 1)
      return sum;

    int weight = paths[i].first;
    auto edge = paths[i].second;
    int start = edge.first;
    int end = edge.second;

    if (Union(start, end))
    {
      sum += weight;
      cnt++;
    }
  }

  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  parent.resize(N + 1);
  lv.resize(N + 1);

  for (int i = 1; i <= N; i++)
  {
    parent[i] = i;
    lv[i] = 1;
  }

  while (M--)
  {
    int s, e, w;
    cin >> s >> e >> w;

    paths.push_back({w, {s, e}});
  }

  sort(paths.begin(), paths.end());
  cout << kruskal();

  return 0;
}
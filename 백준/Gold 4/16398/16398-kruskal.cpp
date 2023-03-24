#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node
{
  int current;
  int cost;
  int next;

  Node(int s, int c, int n) : current(s), cost(c), next(n){};
};

bool compare(const Node &a, const Node &b)
{
  return a.cost < b.cost;
}

long long N;
vector<vector<long long>> graph;
vector<Node> nodes;
vector<int> parents;
vector<int> levels;

int find(int n)
{
  if (parents[n] == n)
    return n;
  return parents[n] = find(parents[n]);
}

bool Union(int a, int b)
{
  int u = find(a);
  int v = find(b);

  if (u == v)
    return false;

  if (levels[u] > levels[v])
    swap(u, v);

  parents[u] = v;
  levels[v]++;

  return true;
}

long long kruskal()
{
  int cnt = 0;
  long long ans = 0;

  for (Node n : nodes)
  {
    if (Union(n.current, n.next))
    {
      ans += n.cost;
      cnt++;
    }

    if (cnt == N - 1)
      return ans;
  }

  return ans;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;

  parents.resize(N);
  levels.resize(N);
  graph.resize(N, vector<long long>(N));

  for (int i = 0; i < N; i++)
  {
    levels[i] = 1;
    parents[i] = i;
  }

  for (vector<long long> &rows : graph)
    for (long long &cost : rows)
      cin >> cost;

  for (int j = 0; j < N; j++)
  {
    for (int k = 0; k < N; k++)
    {
      if (j == k)
        break;

      Node node(j, graph[j][k], k);
      nodes.push_back(node);
    }
  }

  sort(nodes.begin(), nodes.end(), compare);
  cout << kruskal();

  return 0;
}
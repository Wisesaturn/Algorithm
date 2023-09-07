#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// 2. Krustal Algorithm 구현 (시간 복잡도 O(VlogV))
vector<pair<long long, pair<long long, long long>>> weights;
vector<int> parent;
vector<int> lv;
int V, E;

// find the root
int find(int u)
{
  if (parent[u] == u)
    return u;
  return parent[u] = find(parent[u]);
}

bool isNotUnion(int u, int v)
{
  u = find(u);
  v = find(v);

  if (u == v)
    return false;

  if (lv[u] > lv[v])
    swap(u, v);

  parent[u] = v;

  // union-by-rank (높이가 더 낮은 tree를 높은 tree 밑에 넣음)
  // union-find algorithm으로 하면 Linked-list 형식의 tree가 나올 때 O(N) 시간복잡도 발생 (worst case)
  if (lv[u] == lv[v])
    ++lv[v];

  return true;
}

int kruskal()
{
  int cnt = 0, sum = 0;
  for (int i = 0; i < weights.size(); i++)
  {
    if (cnt >= V - 1)
      break;

    long long weight = weights[i].first;
    auto edge = weights[i].second;
    long long edge_start = edge.first;
    long long edge_end = edge.second;

    if (isNotUnion(edge_end, edge_start))
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

  cin >> V >> E;
  parent.resize(V + 1, 0);
  lv.resize(V + 1, 0);

  // Set
  for (int i = 1; i < V + 1; i++)
  {
    parent[i] = i;
    lv[i] = 1;
  }

  for (int i = 0; i < E; i++)
  {
    long long s, e, w;
    cin >> s >> e >> w;

    weights.push_back({w, {s, e}});
  }

  sort(weights.begin(), weights.end());
  cout << kruskal();

  return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

// 3. Prim Algorithm 구현 (시간 복잡도 우선순위 큐 구현 O(ElogV), 배열 구현 (OV^2))
unordered_map<int, bool> visited;
vector<vector<pair<long long, long long>>> graph;
int V, E;

// priority queue 구현
int prim()
{
  int sum = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
  pq.push({0, 1});

  while (!pq.empty())
  {
    pair<long, long> cur = pq.top();
    pq.pop();

    if (visited[cur.second])
      continue;

    visited[cur.second] = true;
    sum += cur.first;

    for (auto edge : graph[cur.second])
      if (!visited[edge.second])
        pq.push(edge);
  }

  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> V >> E;
  graph.resize(V + 1);

  for (int i = 0; i < E; i++)
  {
    long long s, e, w;
    cin >> s >> e >> w;

    graph[s].push_back({w, e});
    graph[e].push_back({w, s});
  }

  cout << prim();

  return 0;
}

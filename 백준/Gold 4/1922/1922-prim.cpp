#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

vector<vector<pair<int, int>>> graph;
unordered_map<int, bool> visited;

int prim(pair<int, int> start)
{
  int sum = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push(start);

  while (!pq.empty())
  {
    auto cur = pq.top();
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

  int N, M;
  cin >> N >> M;

  graph.resize(N + 1, vector<pair<int, int>>());

  while (M--)
  {
    int s, e, w;
    cin >> s >> e >> w;

    graph[s].push_back({w, e});
    graph[e].push_back({w, s});
  }

  cout << prim({0, 1});

  return 0;
}
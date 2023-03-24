#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

long long N, ans = 0;
vector<vector<long long>> graph;
unordered_map<long long, bool> visited;

struct Node
{
  long long cost;
  long long next;

  Node(long long c, long long n) : cost(c), next(n) {}
};

struct compare
{
  bool operator()(const Node &a, const Node &b)
  {
    return a.cost > b.cost;
  }
};

void prim(long long node, long long cost)
{
  priority_queue<Node, vector<Node>, compare> pq;
  Node start(cost, node);
  pq.push(start);

  long long cnt = 0;

  while (!pq.empty())
  {
    Node cur = pq.top();
    pq.pop();

    if (visited[cur.next])
      continue;

    visited[cur.next] = true;
    cnt++;
    ans += cur.cost;

    if (cnt == N)
      return;

    for (long long i = 0; i < N; i++)
    {
      if (visited[i])
        continue;

      Node nextNode(graph[cur.next][i], i);
      pq.push(nextNode);
    }
  }
}

int main(long long argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;

  graph.resize(N, vector<long long>(N));

  for (vector<long long> &rows : graph)
    for (long long &cost : rows)
      cin >> cost;

  prim(0, 0);

  cout << ans;

  return 0;
}
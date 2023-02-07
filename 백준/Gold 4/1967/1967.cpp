#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
vector<vector<pair<int, int>>> tree;
unordered_map<int, bool> visited;
int leaf, sum, N;

void dfs(int node, int length)
{
  visited[node] = true;

  if (sum < length)
  {
    sum = length;
    leaf = node;
  }

  for (auto edge : tree[node])
  {
    if (visited[edge.second])
      continue;
    dfs(edge.second, length + edge.first);
  }

  visited[node] = false;
  return;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  tree.resize(N + 1, vector<pair<int, int>>());

  for (int i = 0; i < N - 1; i++)
  {
    int s, e, w;
    cin >> s >> e >> w;
    tree[s].push_back({w, e});
    tree[e].push_back({w, s});
  }

  dfs(1, 0);
  dfs(leaf, 0);

  cout << sum;

  return 0;
}

// 어느 정점이든 가장 멀리 있는 정점을 찾는다면, 지름에 닿는 두 정점 중 하나
// 그 정점을 찾았을 때, 다시 거기서 반대 방향으로 가장 멀리 있는 정점을 찾는다면 그 길이가 바로 지름
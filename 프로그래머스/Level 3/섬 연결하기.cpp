#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct compare
{
  bool operator()(vector<int> &a, vector<int> &b)
  {
    return a[2] > b[2];
  }
};

unordered_map<int, bool> visited;
vector<int> lv;
vector<int> parent;
priority_queue<vector<int>, vector<vector<int>>, compare> pq;

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

  // u가 v보다 더 깊으면 swap
  if (lv[u] > lv[v])
    swap(u, v);

  // v가 높은 것으로 여기선 간주
  parent[u] = v;

  // union-by-rank (높이가 더 낮은 tree를 높은 tree 밑에 넣음)
  // union-find algorithm으로 하면 Linked-list 형식의 tree가 나올 때 O(N) 시간복잡도 발생 (worst case)
  if (lv[u] == lv[v])
    ++lv[v];

  return true;
}

int kruskal(int n)
{
  int cnt = 0, sum = 0;

  while (!pq.empty())
  {
    if (cnt >= n - 1)
      break;

    auto cur = pq.top();
    pq.pop();

    int from = cur[0];
    int to = cur[1];
    int cost = cur[2];

    if (isNotUnion(from, to))
    {
      sum += cost;
      cnt++;
      // cout << from << " " << to << " " << cost << endl;
    }
  }

  return sum;
}

int solution(int n, vector<vector<int>> costs)
{
  lv.resize(n + 1, 0);
  parent.resize(n + 1, 0);

  // 0. settings
  for (int i = 1; i < n + 1; i++)
  {
    lv[i] = 1;
    parent[i] = i;
  }

  for (auto c : costs)
    pq.push(c);

  return kruskal(n);
}
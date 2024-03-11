#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
unordered_map<int, bool> visited;

int solution(int n, vector<vector<int>> edge)
{
  int ans = 0;
  vector<int> cnt(n + 1, 0);
  queue<pair<int, int>> q;
  vector<vector<int>> graph(n + 1, vector<int>());
  q.push({1, 0});
  visited[1] = true;

  // 0. O(1)이 나오도록 graph 수정
  for (auto e : edge)
  {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  graph[0].push_back(1);

  // 1. 1번부터 출발해서 만나는 노드들의 cnt vector update
  while (!q.empty())
  {
    // {x, y} : {node, num}
    auto cur = q.front();
    q.pop();

    if (cnt[cur.first] < cur.second)
      cnt[cur.first] = cur.second;

    for (auto nextNode : graph[cur.first])
    {
      if (visited[nextNode])
        continue;
      visited[nextNode] = true;
      q.push({nextNode, cur.second + 1});
    }
  }

  // 2. cnt vector 중 제일 큰 원소를 가진 index 출력
  int maxCnt = *max_element(cnt.begin(), cnt.end());
  for (int i = 0; i <= n; i++)
  {
    if (cnt[i] == maxCnt)
      ans++;
  }

  return ans;
}
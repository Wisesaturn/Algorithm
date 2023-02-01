#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<vector<int>> v;
vector<int> p;
unordered_map<int, bool> visited;
queue<int> q;

void bfs()
{
  while (!q.empty())
  {
    int cur = q.front();
    visited[cur] = true;
    q.pop();

    for (int i : v[cur])
    {
      if (!visited[i])
      {
        p[i] = cur;
        q.push(i);
      }
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;

  v.resize(N + 1);
  p.resize(N + 1, 0);
  q.push(1);

  while (N--, N > 0)
  {
    int s, e;
    cin >> s >> e;

    v[s].push_back(e);
    v[e].push_back(s);
  }

  bfs();

  for (int i = 2; i < p.size(); i++)
    cout << p[i] << "\n";

  return 0;
}
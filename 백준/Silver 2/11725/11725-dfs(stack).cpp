#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int N;
vector<vector<int>> v;
vector<int> p;
unordered_map<int, bool> visited;
stack<int> st;

void dfs()
{
  int cur = st.top();
  visited[cur] = true;
  for (int i : v[cur])
  {
    if (!visited[i])
    {
      p[i] = cur;
      st.push(i);
      dfs();
      st.pop();
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  v.resize(N + 1);
  p.resize(N + 1, 0);

  while (N--, N > 0)
  {
    int s, e;
    cin >> s >> e;

    v[s].push_back(e);
    v[e].push_back(s);
  }

  st.push(1);
  dfs();

  for (int i = 2; i < p.size(); i++)
    cout << p[i] << "\n";

  return 0;
}
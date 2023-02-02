#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> v;
vector<int> selected;
unordered_map<int, bool> visited;

void dfs(int n)
{
  for (int i : v[n])
  {
    if (!visited[i])
    {
      visited[i] = true;
      selected.push_back(i);
      dfs(i);
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  v.resize(N + 1, vector<int>(0));

  while (M--)
  {
    int s, e;
    cin >> s >> e;
    v[s].push_back(e);
    v[e].push_back(s);
  }

  visited[1] = true;
  dfs(1);

  cout << selected.size();

  return 0;
}
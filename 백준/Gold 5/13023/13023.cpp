#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M, cnt = 0;
bool hasFriends = false;
vector<vector<int>> connection;
unordered_map<int, bool> visited;

void dfs(int i, int init)
{
  if (cnt == 5)
  {
    hasFriends = true;
    return;
  }

  for (int j = 0; j < connection[i].size(); j++)
  {
    int man = connection[i][j];

    if (visited[man])
      continue;

    visited[man] = true;
    cnt++;
    dfs(man, init);
    visited[man] = false;
    cnt--;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  connection.resize(N, vector<int>());

  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    connection[a].push_back(b);
    connection[b].push_back(a);
  }

  for (int i = 0; i < N; i++)
  {
    visited[i] = true;
    cnt++;
    dfs(i, i);

    if (hasFriends)
      break;

    visited[i] = false;
    cnt--;
  }

  cout << (hasFriends ? 1 : 0) << endl;

  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> positions(11, vector<int>(11));
unordered_map<int, bool> visited;

int dfs(int depth)
{
  int cal = 0, bigger = 0;

  for (int i = 0; i < 11; i++)
  {
    if (visited[i] || positions[i][depth] == 0)
      continue;

    if (depth == 10)
      return positions[i][depth];

    cal = positions[i][depth];

    visited[i] = true;
    int next = dfs(depth + 1);

    if (next == 0)
    {
      visited[i] = false;
      continue;
    }

    cal += next;

    if (bigger < cal)
      bigger = cal;
    visited[i] = false;
  }

  return bigger;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int C;
  cin >> C;

  while (C--)
  {
    for (vector<int> &man : positions)
      for (int &position : man)
        cin >> position;

    cout << dfs(0) << "\n";
  }

  return 0;
}
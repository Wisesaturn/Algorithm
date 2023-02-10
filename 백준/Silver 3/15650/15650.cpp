#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> visited;
vector<int> st;

void dfs(int n, int m, int depth)
{
  if (depth == m + 1)
  {
    for (int ele : st)
      cout << ele << " ";
    cout << "\n";
    return;
  }

  for (int i = depth; i <= n; i++)
  {
    if (st.size() != 0 && st.back() >= i)
      continue;
    st.push_back(i);
    dfs(n, m, depth + 1);
    st.pop_back();
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  dfs(N, M, 1);

  return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> st;

void message()
{
  for (int i = 0; i < st.size(); i++)
    cout << st[i] << " ";
  cout << "\n";
}

void dfs(int n, int m)
{
  for (int i = 1; i <= n; i++)
  {
    st.push_back(i);
    if (st.size() < m)
      dfs(n, m);
    else
      message();
    st.pop_back();
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  dfs(N, M);

  return 0;
}
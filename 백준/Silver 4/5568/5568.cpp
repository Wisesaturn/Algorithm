#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> checked;
unordered_map<int, bool> visited;
vector<int> cards;

int n, k, cnt = 0;

void dfs(int depth, string s)
{
  string tmp = s;

  for (int i = 0; i < n; i++)
  {
    s += to_string(cards[i]);

    if (depth > k)
      return;

    if (visited[i])
    {
      s = tmp;
      continue;
    }

    if (depth == k && !checked[s])
    {
      cnt++;
      checked[s] = true;
    }

    visited[i] = true;
    dfs(depth + 1, s);
    visited[i] = false;
    s = tmp;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> n >> k;

  cards.resize(n);

  for (int &card : cards)
    cin >> card;

  dfs(1, "");

  cout << cnt;

  return 0;
}
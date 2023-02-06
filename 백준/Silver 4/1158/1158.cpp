#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, K, cnt = 0;
  cin >> N >> K;

  queue<int> q;
  vector<int> ans;

  for (int i = 1; i <= N; i++)
    q.push(i);

  while (cnt++, ans.size() < N)
  {
    if (cnt == K)
    {
      ans.push_back(q.front());
      q.pop();
      cnt = 0;
    }
    else if (cnt < K)
    {
      q.push(q.front());
      q.pop();
    }
  }

  cout << "<";
  for (int i = 0; i < ans.size() - 1; i++)
    cout << ans[i] << ", ";
  cout << ans.back() << ">";

  return 0;
}
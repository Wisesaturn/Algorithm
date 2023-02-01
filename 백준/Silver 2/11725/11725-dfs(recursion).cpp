#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<vector<int>> v;
vector<int> p;
unordered_map<int, bool> visited;

void dfs(int n)
{
  visited[n] = true;
  for (int i : v[n])
  {
    if (!visited[i])
    {
      p[i] = n;
      dfs(i);
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

  dfs(1);

  for (int i = 2; i < p.size(); i++)
    cout << p[i] << "\n";

  return 0;
}

// 단순 2차원 배열로 boolean 값을 통해 연결되어 있는 점을 체크 -> 메모리 초과
// 쓸데 없는 false 값들이 너무 많이 잡아먹음
// vector의 push_back을 이용하여 연결되어 있는 점들만 값을 받도록 함 (Linked-List)
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int N;
// vector<vector<bool>> v;
// vector<int> p;
// unordered_map<int, bool> visited;

// void dfs(int n)
// {
//   visited[n] = true;
//   for (int i = 2; i < v.size() + 1; i++)
//   {
//     if (!visited[i] && v[n][i])
//     {
//       p[i] = n;
//       dfs(i);
//     }
//   }
// }

// int main(int argc, char *argv[])
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL), cout.tie(NULL);

//   cin >> N;
//   v.resize(N + 1, vector<bool>(N + 1, false));
//   p.resize(N + 1, 0);

//   while (N--, N > 0)
//   {
//     int s, e;
//     cin >> s >> e;

//     v[s][e] = true;
//     v[e][s] = true;
//   }

//   dfs(1);

//   for (int i = 2; i < p.size(); i++)
//     cout << p[i] << "\n";

//   return 0;
// }
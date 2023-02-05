#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

queue<int> q;
unordered_map<int, int> parent;
vector<int> path;
int N, K;

vector<int> bfs()
{
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();

    if (cur == K)
    {
      while (cur != N)
      {
        path.push_back(cur);
        cur = parent[cur];
      }
      path.push_back(N);
      cout << path.size() - 1 << "\n";
      return path;
    }

    for (int after : {cur + 1, cur - 1, cur * 2})
    {
      if (after >= 0 && after <= 100000 && parent.count(after) == 0)
      {
        parent[after] = cur;
        q.push(after);
      }
    }
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> K;

  parent[N] = -1;
  q.push(N);

  for (int i = bfs().size() - 1; i >= 0; i--)
    cout << path[i] << " ";

  return 0;
}

// 실패 사례.
// 처음엔 path 자체를 queue로 끌고가서 메모리 초과 및 시간 초과가 남
// 소스
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <utility>

// using namespace std;

// queue<pair<int, vector<int>>> q;
// unordered_map<int, bool> visited;
// vector<int> path;
// int N, K;

// vector<int> bfs()
// {
//   while (!q.empty())
//   {
//     int cur = q.front().first;
//     path = q.front().second;
//     q.pop();

//     if (cur == K)
//     {
//       cout << path.size() - 1 << "\n";
//       return path;
//     }

//     if (visited[cur])
//       continue;

//     visited[cur] = true;

//     if (cur + 1 <= 100000)
//     {
//       path.push_back(cur + 1);
//       q.push({cur + 1, path});
//       path.pop_back();
//     }

//     if (cur - 1 >= 0)
//     {
//       path.push_back(cur - 1);
//       q.push({cur - 1, path});
//       path.pop_back();
//     }

//     if (cur * 2 <= 100000)
//     {
//       path.push_back(cur * 2);
//       q.push({cur * 2, path});
//       path.pop_back();
//     }
//   }
// }

// int main(int argc, char *argv[])
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL), cout.tie(NULL);

//   cin >> N >> K;

//   path.push_back(N);
//   q.push({N, path});

//   for (int i : bfs())
//     cout << i << " ";

//   return 0;
// }
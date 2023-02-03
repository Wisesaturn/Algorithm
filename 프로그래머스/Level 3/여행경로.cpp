#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<vector<string>> ans(1, vector<string>());
unordered_map<int, bool> visited;

void dfs(vector<string> routes, vector<vector<string>> tickets)
{
  if (routes.size() == tickets.size() + 1)
  {
    ans.push_back(routes);
    return;
  }

  size_t idx = 0;
  for (vector<string> ticket : tickets)
  {
    if (!visited[idx])
    {
      if (ticket[0] == routes.back())
      {
        visited[idx] = true;
        routes.push_back(ticket[1]);
        dfs(routes, tickets);
        routes.pop_back();
        visited[idx] = false;
      }
    }
    idx++;
  }

  return;
}

vector<string> solution(vector<vector<string>> tickets)
{
  vector<string> routes;
  routes.push_back("ICN");
  dfs(routes, tickets);

  sort(ans.begin(), ans.end());

  return ans[1];
}
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<int, bool> visited;

vector<string> dfs(string location, vector<vector<string>> tickets)
{
  vector<string> st;
  size_t idx = 0;

  for (vector<string> ticket : tickets)
  {
    if (!visited[idx] && ticket[0] == location)
    {
      visited[idx] = true;
      for (string element : dfs(ticket[1], tickets))
        st.push_back(element);
      st.push_back(ticket[1]);
    }
    idx++;
  }

  return st;
}

vector<string> solution(vector<vector<string>> tickets)
{
  sort(tickets.begin(), tickets.end());
  vector<string> routes;

  for (auto e : dfs("ICN", tickets))
    routes.push_back(e);
  routes.push_back("ICN");
  reverse(routes.begin(), routes.end());

  return routes;
}
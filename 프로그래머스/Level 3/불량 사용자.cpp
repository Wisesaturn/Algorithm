#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, bool> visited;
unordered_map<string, bool> checked;
vector<vector<string>> match;
vector<string> check;

int ans = 0;
int limit = 0;

bool isMatch(string a, string b)
{
  if (a.size() != b.size())
    return false;

  for (int i = 0; i < b.size(); i++)
  {
    if (b[i] == '*')
      continue;

    if (a[i] != b[i])
      return false;
  }

  return true;
}

void dfs(string &s, int depth)
{
  if (depth == limit)
  {
    string checkStr = "";
    vector<string> tmpCheck;

    for (string s : check)
      tmpCheck.push_back(s);
    sort(tmpCheck.begin(), tmpCheck.end());

    for (string s : tmpCheck)
    {
      checkStr += s;
    }

    if (!checked[checkStr])
    {
      ans++;
      checked[checkStr] = true;
    }

    return;
  }

  for (int j = 0; j < match[depth].size(); j++)
  {
    if (visited[match[depth][j]])
      continue;

    visited[match[depth][j]] = true;
    check.push_back(match[depth][j]);
    dfs(match[depth][j], depth + 1);
    check.pop_back();
    visited[match[depth][j]] = false;
  }

  return;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
  limit = banned_id.size();
  match.resize(banned_id.size(), vector<string>());

  // 1. banid와 userid가 일치하는가?
  for (int i = 0; i < banned_id.size(); i++)
  {
    for (int j = 0; j < user_id.size(); j++)
    {
      if (isMatch(user_id[j], banned_id[i]))
      {
        match[i].push_back(user_id[j]);
      }
    }
  }

  // 2. dfs 방식으로 순회해서 count
  for (int i = 0; i < match[0].size(); i++)
  {
    visited[match[0][i]] = true;
    check.push_back(match[0][i]);
    dfs(match[0][i], 1);
    check.pop_back();
    visited[match[0][i]] = false;
  }

  // // match 출력
  // for (int i = 0; i < match.size(); i++) {
  //     for (int j = 0; j < match[i].size() ; j++) {
  //         cout << match[i][j] << " ";
  //     }
  //     cout << endl;
  // }

  return ans;
}
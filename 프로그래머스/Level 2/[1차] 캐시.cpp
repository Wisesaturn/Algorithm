#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cctype>
#include <iostream>

using namespace std;

unordered_map<string, bool> cache;

// transform(s.begin(), s.end(), s.begin(), ::tolower
// 를 이용해도 가능
string toLower(string s)
{
  string str = "";
  for (char c : s)
  {
    str += tolower(c);
  }

  return str;
}

int solution(int cacheSize, vector<string> cities)
{
  int ans = 0;
  int countCache = 0;
  priority_queue<pair<int, string>, vector<pair<int, string>>, less<>> cacheString;
  queue<pair<int, string>> q;

  for (string originCity : cities)
  {
    string city = toLower(originCity);

    if (cache[city])
    {
      ans += 1;

      while (!cacheString.empty())
      {
        auto cur = cacheString.top();
        cacheString.pop();

        if (cur.second == city)
        {
          q.push({1, cur.second});
        }
        else
        {
          q.push({cur.first + 1, cur.second});
        }
      }

      while (!q.empty())
      {
        auto cur = q.front();
        q.pop();
        cacheString.push(cur);
      }
    }
    else if (countCache < cacheSize)
    {
      ans += 5;
      cache[city] = true;
      countCache++;
      bool hasQueue = false;

      while (!cacheString.empty())
      {
        auto cur = cacheString.top();
        cacheString.pop();

        if (cur.second == city)
        {
          q.push({1, cur.second});
          hasQueue = true;
        }
        else
        {
          q.push({cur.first + 1, cur.second});
        }
      }

      while (!q.empty())
      {
        auto cur = q.front();
        q.pop();
        cacheString.push(cur);
      }

      if (!hasQueue)
      {
        cacheString.push({1, city});
      }
    }
    else
    {
      if (cacheSize > 0)
      {
        cache[city] = true;
        bool hasQueue = false;

        while (!cacheString.empty())
        {
          auto cur = cacheString.top();
          cacheString.pop();

          if (cur.second == city)
          {
            q.push({1, cur.second});
            hasQueue = true;
          }
          else
          {
            q.push({cur.first + 1, cur.second});
          }
        }

        while (!q.empty())
        {
          auto cur = q.front();
          q.pop();
          cacheString.push(cur);
        }

        if (!hasQueue)
        {
          cacheString.push({1, city});
        }

        auto deleteCache = cacheString.top();
        cacheString.pop();
        cache[deleteCache.second] = false;
      }

      ans += 5;
    }
  }

  return ans;
}
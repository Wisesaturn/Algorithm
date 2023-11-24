#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
  vector<int> ans;
  int cnt = 0;
  int maxLength = 0;

  // 0. 입력 받기
  vector<vector<int>> arr;
  vector<int> tmpArr;
  string tmpStr;
  stringstream ss(s);

  char c;

  while (ss >> c)
  {
    if (c >= '0' && c <= '9')
    {
      tmpStr += c;
    }
    else if (c == '}' || c == ',')
    {
      if (tmpStr.size() > 0)
      {
        tmpArr.push_back(stoi(tmpStr));
      }
      tmpStr = "";
    }
    else if (c == '{')
    {
      if (tmpArr.size() > 0)
      {
        arr.push_back(tmpArr);
        tmpArr.clear();
      }
    }
  }

  if (tmpArr.size() > 0)
  {
    arr.push_back(tmpArr);
    tmpArr.clear();
  }

  for (int i = 0; i < arr.size(); i++)
    sort(arr[i].begin(), arr[i].end());

  // 1. 튜플의 길이 찾기
  maxLength = max_element(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
                          { return a.size() < b.size(); })
                  ->size();

  // 2. 튜플의 길이를 채울 때까지 반복
  while (cnt++, cnt <= maxLength)
  {
    auto targetIt = find_if(arr.begin(), arr.end(), [cnt](const vector<int> &a)
                            { return a.size() == cnt; });
    vector<int> target = *targetIt;

    for (int i = 0; i < target.size(); i++)
    {
      auto it = find(ans.begin(), ans.end(), target[i]);

      if (it == ans.end())
      {
        ans.push_back(target[i]);
        break;
      }
    }
  }

  return ans;
}

// 완전탐색인데 결론적으론
// 가장 많이 나온 숫자에 따라서 차근차근 쌓아두면 되는 쉬운 방식이 있다.
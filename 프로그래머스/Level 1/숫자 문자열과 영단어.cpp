
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <regex>

using namespace std;

unordered_map<string, string> convertNum;

bool isNum(char c)
{
  if (c >= '0' && c <= '9')
    return true;
  return false;
}

int solution(string s)
{
  string ans = "";
  string tmp = "";
  // 1. Map 형성
  convertNum["zero"] = "0";
  convertNum["one"] = "1";
  convertNum["two"] = "2";
  convertNum["three"] = "3";
  convertNum["four"] = "4";
  convertNum["five"] = "5";
  convertNum["six"] = "6";
  convertNum["seven"] = "7";
  convertNum["eight"] = "8";
  convertNum["nine"] = "9";

  // 2. check string

  for (int i = 0; i < s.size(); i++)
  {

    if (isNum(s[i]))
    {
      if (tmp.size() != 0)
      {
        ans += convertNum[tmp];
        tmp = "";
      }
      ans += s[i];
      continue;
    }

    if (convertNum[tmp] != "")
    {
      ans += convertNum[tmp];
      tmp = "";
    }

    tmp += s[i];
    // cout << ans << " "<< s[i] << endl;
  }

  if (convertNum[tmp] != "")
  {
    ans += convertNum[tmp];
  }

  return ans != "" ? stoi(ans) : 0;
}

// 정규식을 활용하면 쉽게 풀 수 있다.
// regex_replace(string, 정규식, 바꿀 문자열);
// ex) regex_replace(s, regex("three"), "3");

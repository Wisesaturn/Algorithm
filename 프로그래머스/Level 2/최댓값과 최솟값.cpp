#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s)
{
  string ans = "";
  int tmp, output;
  stringstream ss(s);
  ss >> output;

  vector<int> list;

  while (tmp != output)
  {
    tmp = output;
    ss >> output;
    list.push_back(tmp);

    if (tmp == output)
      break;
  }

  sort(list.begin(), list.end());
  ans += to_string(list[0]);
  ans += " ";
  ans += to_string(list[list.size() - 1]);

  return ans;
}
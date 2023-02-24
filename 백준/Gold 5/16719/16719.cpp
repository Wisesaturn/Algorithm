#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> print(string str)
{
  vector<string> order, fronts, backs;
  string copyStr = str;
  sort(copyStr.begin(), copyStr.end());

  string tmp = "";
  tmp += copyStr.front();
  order.push_back(tmp);

  if (str.size() <= 1)
    return order;

  int idx = str.find(tmp);

  if (idx + 1 < str.size())
  {
    backs = print(str.substr(idx + 1));
    for (string back : backs)
      order.push_back(tmp + back);
  }

  if (idx > 0)
  {
    fronts = print(str.substr(0, idx));
    for (string front : fronts)
      order.push_back(front + str.substr(idx));
  }

  return order;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  string input;
  cin >> input;

  vector<string> printings = print(input);

  for (string str : printings)
    cout << str << "\n";

  return 0;
}
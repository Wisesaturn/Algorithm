#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  map<string, bool> s;
  set<string> list;

  while (N--)
  {
    string tmp;
    cin >> tmp;
    s[tmp] = true;
  }

  while (M--)
  {
    string tmp;
    cin >> tmp;
    if (s[tmp])
      list.insert(tmp);
  }

  cout << list.size() << "\n";

  for (string s : list)
    cout << s << "\n";

  return 0;
}
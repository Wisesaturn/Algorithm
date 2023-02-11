#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int N, M;

  cin >> N >> M;
  unordered_map<string, int> info;
  vector<string> names(N + 1);

  for (int i = 1; i <= N; i++)
  {
    string tmp;
    cin >> tmp;
    names[i] = tmp;
    info[tmp] = i;
  }

  while (M--)
  {
    string input;
    cin >> input;

    if (info.count(input) != 0)
      cout << info[input] << "\n";
    else
      cout << names[stoi(input)] << "\n";
  }

  return 0;
}
#include <iostream>
#include <string>

using namespace std;

string isCorrect(string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(' && s[i + 1] == ')')
    {
      s.replace(i, 2, "");
      i = -1;
    }
  }

  return s.size() == 0 ? "YES" : "NO";
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;

  while (N--)
  {
    string tmp;
    cin >> tmp;
    cout << isCorrect(tmp) << "\n";
  }
  return 0;
}
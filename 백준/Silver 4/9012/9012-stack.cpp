#include <iostream>
#include <string>
#include <stack>

using namespace std;

string isCorrect(string s)
{
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (!st.empty() && st.top() == '(' && s[i] == ')')
      st.pop();
    else
      st.push(s[i]);
  }

  return st.empty() ? "YES" : "NO";
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
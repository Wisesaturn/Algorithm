#include <string>
#include <stack>

using namespace std;

char isCorrectX[] = {'(', '[', '{'};
char isCorrectY[] = {')', ']', '}'};

bool isCorrect(string s)
{
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
    {
      st.push(s[i]);
      continue;
    }
    else
    {
      if (st.empty())
        return false;

      for (int j = 0; j < 3; j++)
      {
        if (!st.empty() && st.top() == isCorrectX[j] && s[i] == isCorrectY[j])
        {
          st.pop();
          break;
        }
      }
    }
  }

  return st.empty();
}

int solution(string s)
{
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
  {
    char tmp = s.front();
    s = s.substr(1);
    s.push_back(tmp);

    if (isCorrect(s))
      cnt++;
  }

  return cnt;
}
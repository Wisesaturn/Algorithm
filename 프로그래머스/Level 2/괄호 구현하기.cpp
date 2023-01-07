#include <string>

using namespace std;

char isCorrectX[] = {'(', '[', '{'};
char isCorrectY[] = {')', ']', '}'};

bool isCorrect(string s)
{
  for (int i = 0; i < s.size(); i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (s[i] == isCorrectX[j] && s[i + 1] == isCorrectY[j])
      {
        s.replace(i, 2, "");
        i = -1;
        break;
      }
    }
  }

  return s.size() == 0;
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
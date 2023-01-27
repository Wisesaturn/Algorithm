#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> v;
// visited 확인용 (key-value 자료구조를 통해 문자열 중복 체크)

set<string> solution(string s)
{
  set<string> list;
  stack<int> st;

  if (v[s])
    return list;
  v[s] = true;
  // v.insert(make_pair(s, true)) 혹은 v.insert(pair<string, bool>(s, true))도 가능

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      st.push(i);
    else if (s[i] == ')')
    {
      int tmp = st.top();
      st.pop();
      string newstr = s.substr(0, tmp) + s.substr(tmp + 1, i - tmp - 1) + s.substr(i + 1);
      list.insert(newstr);
      for (string tmpstr : solution(newstr))
        list.insert(tmpstr);
    }
  }

  return list;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  string s;
  getline(cin, s);
  set<string> list = solution(s);
  // set STL을 쓰면 알아서 자동 정렬된다 (sort할 필요 없음)

  for (string e : list)
    cout << e << "\n";

  return 0;
}

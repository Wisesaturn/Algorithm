#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getNum(int s, int n)
{
  string st = "";

  while (s > 0)
  {
    if (s % 2 == 1)
    {
      st += "1";
    }
    else
    {
      st += "0";
    }

    s /= 2;
  }

  while (st.size() < n)
  {
    st += "0";
  }

  reverse(st.begin(), st.end());
  return st;
}

string getInitial(int n)
{
  string st = "";
  while (st.size() < n)
  {
    st += "#";
  }

  return st;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
  vector<string> ans(n, getInitial(n));

  // 1. 이진수를 #으로 바꾸어보자
  for (int i = 0; i < n; i++)
  {
    string num1 = getNum(arr1[i], n);
    string num2 = getNum(arr2[i], n);

    for (int j = 0; j < n; j++)
    {
      if (num1[j] != '1' && num2[j] != '1')
      {
        ans[i][j] = ' ';
      }
    }
  }

  return ans;
}

#include <vector>

using namespace std;

int gcd(int x, int y)
{
  int tmp, a, b;
  if (x > y)
  {
    a = x;
    b = y;
  }
  else
  {
    a = y;
    b = x;
  }
  while (b)
  {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int lcm(int x, int y)
{
  return (x * y) / gcd(x, y);
}

vector<int> solution(int n, int m)
{
  vector<int> ans;
  ans.push_back(gcd(n, m));
  ans.push_back(lcm(n, m));
  return ans;
}
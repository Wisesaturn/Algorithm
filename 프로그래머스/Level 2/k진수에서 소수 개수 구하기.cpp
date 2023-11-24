#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

string getPrime(int n, int k)
{
  string str = "";

  while (n > 0)
  {
    long long tmp = n % k;
    str += to_string(tmp);
    n /= k;
  }

  reverse(str.begin(), str.end());
  return str;
}

bool isPrime(long long n)
{
  if (n <= 1)
    return false;

  // 2부터 n의 제곱근까지 나누어 떨어지는지 파악
  for (long long i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }

  return true;
}

int solution(int n, int k)
{
  vector<long long> cnt;

  // 0. k진수로 바꾸고 string 출력
  string target = getPrime(n, k);
  // cout << target;
  string tmpStr = "";

  // 2. P 조건 찾아서 count
  for (int i = 0; i < target.size(); i++)
  {
    if (target[i] == '0')
    {
      // 3. 찾으면 cnt에 insert
      if (!tmpStr.empty())
      {
        if (isPrime(stoll(tmpStr)))
        {
          cnt.push_back(stoll(tmpStr));
        }
        tmpStr = "";
      }
    }
    else
    {
      tmpStr += target[i];
      // cout << tmpStr << endl;
    }
  }

  if (!tmpStr.empty() && isPrime(stoll(tmpStr)))
  {
    cnt.push_back(stoll(tmpStr));
  }

  // for (auto it = cnt.begin() ; it != cnt.end(); it++)
  // cout << *it << endl;

  return cnt.size() ? cnt.size() : 0;
}

// 소수 판별 로직
// 1. 2부터 해당 숫자의 제곱근까지 나누어 떨어지는가?
// 2. 에라토스테네스의 체 -> 이건 외워야 할 듯

// 소수 구할 때
// 나머지로 구하고, reverse

// 문제 잘 읽기
// 소수 자체를 빼먹어서 오래 걸렸다. 소수를 기준인데 특정 소수를 구하는 것
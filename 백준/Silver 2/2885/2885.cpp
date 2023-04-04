#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void test(int K)
{
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int K, size = 0, cnt = 0, sum = 0, choose = 0;
  cin >> K;

  for (int i = 0; i <= 20; i++)
  {
    if (K <= pow(2, i))
    {
      size = pow(2, i);
      choose = size;
      break;
    }
  }

  if (K == size)
    sum = size;

  while (sum != K)
  {
    size /= 2;
    cnt++;

    if (sum + size <= K)
      sum += size;
  }

  cout << choose << " " << cnt;

  return 0;
}

// 16분
// Binary Search 하듯이 계속 2등분해서 나누면 된다.
// 2진수 계산하는 느낌이랑 비슷한 듯 (입력값의 한 단계 더 높은 초콜릿을 choice)
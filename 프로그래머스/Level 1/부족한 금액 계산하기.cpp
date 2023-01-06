using namespace std;

long long solution(int price, int money, int count)
{
  long long pay = 0;
  for (int i = 1; i <= count; i++)
    pay += price * i;
  return money - pay > 0 ? 0 : -1 * (money - pay);
}
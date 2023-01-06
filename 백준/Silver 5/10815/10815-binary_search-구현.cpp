#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> arr;

bool binarySearch(const long long &data)
{
  int l, m, h;
  l = 0;
  h = arr.size() - 1;

  while (1)
  {
    m = (l + h) / 2;

    if (l > m || h < m)
      return false;

    if (arr[m] > data)
      h = m - 1;
    else if (arr[m] < data)
      l = m + 1;
    else if (arr[m] == data)
      return true;
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;

  while (N--)
  {
    long long temp;
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());
  int M;
  cin >> M;

  while (M--)
  {
    long long temp;
    cin >> temp;
    if (binarySearch(temp))
      cout << "1";
    else
      cout << "0";
    cout << " ";
  }

  return 0;
}
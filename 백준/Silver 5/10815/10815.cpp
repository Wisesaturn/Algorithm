#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;

  vector<long long> arr;

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
    if (binary_search(arr.begin(), arr.end(), temp))
      cout << "1";
    else
      cout << "0";
    cout << " ";
  }

  return 0;
}
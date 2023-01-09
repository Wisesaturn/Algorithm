#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, K;
  cin >> N >> K;

  vector<int> arr(N);
  vector<int> cnt;

  for (auto &i : arr)
    cin >> i;

  for (int i = 0; i < N; i++)
  {
    int check = arr[i] - (K * i);
    int tmp = 0;

    if (check < 1)
      continue;

    for (int j = 0; j < N; j++)
    {
      if (arr[j] != check + (j * K))
        tmp++;
    }

    cnt.push_back(tmp);
  }

  cout << *min_element(cnt.begin(), cnt.end());

  return 0;
}
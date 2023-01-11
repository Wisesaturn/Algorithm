#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  int idx1 = 0, idx2 = 0;

  vector<int> arr1(n);
  vector<int> arr2(m);

  for (int &i : arr1)
    cin >> i;
  for (int &j : arr2)
    cin >> j;

  while (idx1 < n && idx2 < m)
  {
    if (arr1[idx1] <= arr2[idx2])
      cout << arr1[idx1++] << " ";
    else
      cout << arr2[idx2++] << " ";
  }

  while (idx1 < n)
    cout << arr1[idx1++] << " ";
  while (idx2 < m)
    cout << arr2[idx2++] << " ";
}
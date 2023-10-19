#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine)
{
  int tangerineMax = *max_element(tangerine.begin(), tangerine.end());
  int ans = 0;
  vector<pair<int, int>> countArray(tangerineMax + 1);

  for (int i = 0; i < countArray.size(); i++)
    countArray[i] = {0, i};

  for (int i = 0; i < tangerine.size(); i++)
  {
    int isTangerine = tangerine[i];
    countArray[isTangerine].first++;
  }

  sort(countArray.begin(), countArray.end(), greater<>());
  countArray.erase(remove_if(countArray.begin(), countArray.end(), [](pair<int, int> &element)
                             { return element.first == 0; }),
                   countArray.end());

  for (int j = 0; j <= countArray.size(); j++)
  {
    int nowIndex = countArray[j].second;
    int nowCount = countArray[j].first;
    k -= nowCount;
    ans++;

    if (k <= 0)
      break;
  }

  return ans;
}
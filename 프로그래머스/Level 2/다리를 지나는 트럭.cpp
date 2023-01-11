#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
  reverse(truck_weights.begin(), truck_weights.end());
  vector<int> bridge(bridge_length, 0);
  int cnt = 0;

  while (!truck_weights.empty())
  {
    int curW = 0;

    for (int i = bridge_length - 1; i >= 1; i--)
      bridge[i] = bridge[i - 1];
    bridge[0] = 0;

    for (int &i : bridge)
      curW += i;

    if (curW + truck_weights.back() <= weight)
    {
      bridge[0] = truck_weights.back();
      truck_weights.pop_back();
    }

    cnt++;
  }

  return cnt + bridge_length;
}
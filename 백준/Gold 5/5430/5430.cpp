#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int T;
  cin >> T;

  while (T--)
  {
    // 0. settings
    int n;
    bool isError = false;
    bool isReverse = false;
    string f, inputArr, token;
    deque<int> arr;
    cin >> f >> n >> inputArr;

    // 1. input vector
    stringstream ss(inputArr);
    while (getline(ss, token, ','))
    {
      if (token[0] == '[')
      {
        token.erase(0, 1);
      }

      if (token.back() == ']')
      {
        token.pop_back();
      }

      if (token.size() > 0)
      {
        arr.push_back(stoi(token));
      }
    }

    // 2. calculate function
    for (char c : f)
    {
      if (c == 'R')
      {
        isReverse = !isReverse;
      }
      else if (c == 'D')
      {
        if (arr.size() == 0)
        {
          cout << "error"
               << "\n";
          isError = true;
          break;
        }
        isReverse ? arr.pop_back() : arr.pop_front();
      }
    }

    // 3. output
    if (!isError)
    {
      if (isReverse)
        reverse(arr.begin(), arr.end());

      cout << "[";
      for (int i = 0; i < arr.size(); ++i)
      {
        cout << arr[i];
        if (i < arr.size() - 1)
          cout << ",";
      }
      cout << "]\n";
    }
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // 0. settings
  int N, idx = 0, num = 1;
  cin >> N;

  vector<string> ans;
  vector<int> st;
  vector<int> order(N);
  for (int &n : order)
    cin >> n;

  // cout << "---" << endl;
  // 1. calc stack
  while (idx < N)
  {
    int target = order[idx];
    // cout << idx << " " << num << endl;
    if (num > N)
    {
      if (st.back() == target)
      {
        // cout << "5" << endl;
        st.pop_back();
        ans.push_back("-");
        idx++;
        continue;
      }

      // cout << "6" << endl;
      ans.clear();
      break;
    }

    if (num <= target)
    {
      // cout << "1" << endl;
      ans.push_back("+");
      st.push_back(num);
      num++;
    }
    else if (st.back() == target)
    {
      // cout << "4" << endl;
      st.pop_back();
      ans.push_back("-");
      idx++;
    }
    else if (num > target)
    {
      // cout << "2" << endl;
      ans.clear();
      break;
    }
  }

  // answer
  if (ans.size() > 0)
  {
    for (string s : ans)
      cout << s << "\n";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}
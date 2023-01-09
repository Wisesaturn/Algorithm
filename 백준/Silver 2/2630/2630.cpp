#include <iostream>
#include <vector>
using namespace std;

int W = 0, B = 0;

void isColor(vector<vector<int>> data, int depth)
{
  bool isCorrect = false;
  if (depth < 1)
    return;

  for (int i = 0; i < depth; i++)
  {
    for (int j = 0; j < depth; j++)
    {
      if (isCorrect)
        return;

      if (data[0][0] != data[i][j])
      {
        auto mid_row = data.begin() + data.size() / 2;

        vector<vector<int>> q1(data.begin(), mid_row);
        vector<vector<int>> q2(data.begin(), mid_row);
        vector<vector<int>> q3(mid_row, data.end());
        vector<vector<int>> q4(mid_row, data.end());

        for (auto it = q1.begin(); it != q1.end(); it++)
        {
          auto mid_col = it->begin() + it->size() / 2;
          *it = vector<int>(it->begin(), mid_col);
        }

        for (auto it = q2.begin(); it != q2.end(); it++)
        {
          auto mid_col = it->begin() + it->size() / 2;
          *it = vector<int>(mid_col, it->end());
        }

        for (auto it = q3.begin(); it != q3.end(); it++)
        {
          auto mid_col = it->begin() + it->size() / 2;
          *it = vector<int>(it->begin(), mid_col);
        }

        for (auto it = q4.begin(); it != q4.end(); it++)
        {
          auto mid_col = it->begin() + it->size() / 2;
          *it = vector<int>(mid_col, it->end());
        }

        isColor(q1, depth / 2);
        isColor(q2, depth / 2);
        isColor(q3, depth / 2);
        isColor(q4, depth / 2);

        isCorrect = true;
        if (isCorrect)
          return;
      }
    }
  }

  // result
  if (data[0][0])
    B++;
  else if (!data[0][0])
    W++;

  return;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N;
  cin >> N;
  vector<vector<int>> paper(N, vector<int>(N));

  for (vector<int> &i : paper)
  {
    for (int &j : i)
      cin >> j;
  }

  isColor(paper, N);

  cout << W << "\n";
  cout << B;

  return 0;
}
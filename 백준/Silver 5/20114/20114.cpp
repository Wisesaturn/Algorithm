#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int N, H, W, idx = 0, cnt = 0;
  cin >> N >> H >> W;

  vector<string> text(H);
  string ans(N, '?');

  for (string &setence : text)
    cin >> setence;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < N * W; j++)
    {
      if (text[i][j] == '?')
        continue;

      ans[j / W] = text[i][j];
    }
  }

  cout << ans;

  return 0;
}
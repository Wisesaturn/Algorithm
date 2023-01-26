#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

// struct point 구조체 방법 말고 pair를 통해 해보았음

int dx[] = {1, 0};
int dy[] = {0, 1};
int N;
stack<pair<int, int>> st;
vector<vector<int>> map(0, vector<int>(0, -999));
vector<vector<bool>> v(0, vector<bool>(0, false));
bool isCorrect = false;

void dfs()
{
  pair<int, int> cur = st.top();
  v[cur.first][cur.second] = true;

  if (map[cur.first][cur.second] == -1 || isCorrect)
  {
    isCorrect = true;
    return;
  }

  for (int i = 0; i < 2; i++)
  {
    int nx = cur.first + dx[i] * map[cur.first][cur.second];
    int ny = cur.second + dy[i] * map[cur.first][cur.second];

    if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map.size() || v[nx][ny] == true)
      continue;

    st.push(make_pair(nx, ny));
    dfs();
    st.pop();
  }
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N;
  map.resize(N, vector<int>(N, -999));
  v.resize(N, vector<bool>(N, false));

  for (vector<int> &i : map)
    for (int &j : i)
      cin >> j;

  st.push(make_pair(0, 0));
  dfs();

  isCorrect ? cout << "HaruHaru" : cout << "Hing";

  return 0;
}
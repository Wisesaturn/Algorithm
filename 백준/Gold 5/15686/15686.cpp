#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<vector<int>> map;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  cin >> N >> M;

  map.resize(N, vector<int>(M));

  // 1. M >= 치킨집의 수 : 폐업하는 집이 없다

  

  // 2. M < 치킨집의 수 : 폐업을 시켜야 한다

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;
int n, m;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        auto it = find(ans.begin(), ans.end(), i);

        if (it != ans.end())
            continue;

        ans.push_back(i);
        dfs(cnt + 1);
        ans.pop_back();
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    dfs(0);

    return 0;
}
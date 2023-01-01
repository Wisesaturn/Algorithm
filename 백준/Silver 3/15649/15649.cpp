#include <iostream>

using namespace std;
bool isVisited[8];
int result[8];
int n, m;

void dfs(int start)
{
    if (start == m)
    {
        for (auto i : result)
        {
            if (i != 0)
                cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (isVisited[i])
            continue;
        isVisited[i] = true;
        result[start] = i;
        dfs(start + 1);
        isVisited[i] = false;
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
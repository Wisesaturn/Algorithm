#include <iostream>

using namespace std;

int N, M, R;

int map[301][301];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int ans[301][301] = {
        0,
    };

    while (R--)
    {
        for (int i = 0; i < N / 2; i++)
        {
            int sy = i;
            int sx = i;

            int idx = 0;
            while (1)
            {
                int temp = map[sy][sx];
                int ny = sy + dy[idx];
                int nx = sx + dx[idx];

                if (ny < 0 + i || nx < 0 + i || ny >= N - i || nx >= M - i)
                {
                    idx++;
                    if (idx == 4)
                        break;
                    continue;
                }

                sy = ny;
                sx = nx;
                ans[ny][nx] = temp;
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                map[i][j] = ans[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
#include <iostream>

using namespace std;

int isCount[5000];

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i <= 5000; i++)
        isCount[i] = 99999;

    isCount[3] = isCount[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        isCount[i] = min(isCount[i - 5] + 1, isCount[i - 3] + 1);
    }

    if (isCount[n] >= 99999)
        cout << "-1\n";
    else
        cout << isCount[n] << '\n';

    return 0;
}
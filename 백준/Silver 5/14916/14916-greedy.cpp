#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, result = 0;
    cin >> n;

    while (n > 0)
    {
        if (n % 5 == 0)
        {
            cout << n / 5 + result << "\n";
            return 0;
        }
        n -= 2;
        result++;
    }

    if (n == 0)
        cout << result << "\n";
    else
        cout << "-1\n";

    return 0;
}
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, check;
    int result = 0;
    cin >> n;
    check = n;

    do
    {
        int a, b;
        a = check / 10;
        b = check % 10;
        check = (10 * b) + ((a + b) % 10);

        result++;
    } while (check != n);

    cout << result << "\n";

    return 0;
}
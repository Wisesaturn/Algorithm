#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a & b;
    }
    return b;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        result.push_back(lcm(a, b));
    }

    for (auto i : result)
        cout << i << "\n";

    return 0;
}
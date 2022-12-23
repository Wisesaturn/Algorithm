#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    int answer = 0;
    vector<int> rope;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        rope.push_back(temp);
    }

    sort(rope.begin(), rope.end());

    for (int i = 0; i < n; i++)
        answer = max(answer, (n - i) * rope[i]);

    cout << answer << "\n";

    return 0;
}
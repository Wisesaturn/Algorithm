#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    vector<int> ans;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp != 0)
            ans.push_back(temp);
        else
            ans.pop_back();
    }

    int sum = 0;

    for (int i = 0; i < ans.size(); i++)
        sum += ans[i];

    cout << sum;

    return 0;
}
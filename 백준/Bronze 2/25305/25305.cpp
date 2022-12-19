#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    vector<int> score;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        score.push_back(temp);
    }

    sort(score.begin(), score.end(), greater<int>());

    cout << score[k - 1] << endl;
    return 0;
}
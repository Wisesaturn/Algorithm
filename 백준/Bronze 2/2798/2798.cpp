#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m, max = 0;
    vector<int> cards;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cards.push_back(temp);
    }

    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = i + 1; j < cards.size(); j++)
        {
            if (i == j)
                continue;
            for (int k = i + 2; k < cards.size(); k++)
            {
                if (j == k)
                    continue;

                int add = 0;
                add += cards[i];
                add += cards[j];
                add += cards[k];
                if (max <= add && add <= m)
                    max = add;
            }
        }
    }

    cout << max << "\n";

    return 0;
}
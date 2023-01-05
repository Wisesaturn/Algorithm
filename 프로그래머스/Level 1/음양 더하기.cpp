#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int ans = 0;
    for (int i = 0; i < absolutes.size(); i++)
    {
        if (signs[i])
            ans += absolutes[i];
        else
            ans -= absolutes[i];
    }

    return ans;
}
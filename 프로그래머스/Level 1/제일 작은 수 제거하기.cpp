#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> temp(arr.size());
    copy(arr.begin(), arr.end(), temp.begin());

    sort(temp.begin(), temp.end(), greater<int>());
    vector<int>::iterator it = find(arr.begin(), arr.end(), temp.back());
    arr.erase(it);

    if (arr.size() < 0)
        arr.push_back(-1);

    return arr;
}
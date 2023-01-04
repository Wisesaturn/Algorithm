#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long N, SUM = 0;
    long long arr[100001];
    cin >> N;
    memset(&arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N, greater<>());

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > i)
            SUM += arr[i] - i;
    }

    cout << SUM;

    return 0;
}
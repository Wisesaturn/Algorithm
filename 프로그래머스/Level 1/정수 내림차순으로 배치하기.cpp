#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n)
{
    vector<int> arr;
    arr.push_back(n % 10);

    while (n /= 10, n > 0)
        arr.push_back(n % 10);

    sort(arr.begin(), arr.end());

    long long ans = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int multi = 1;
        for (int j = 0; j < i; j++)
            multi *= 10;
        ans += arr[i] * multi;
    }

    return ans;
}

// string으로 변환 후 sort를 이용하여 정렬
// 그리고 stoll로 바로 숫자 변환하는 과정이 더 빠를 듯
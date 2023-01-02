#include <iostream>

using namespace std;

struct isStack
{
    int arr[100000];
    int it;

    isStack() {}

    void init()
    {
        it = -1;
    }

    void push(int input)
    {
        arr[++it] = input;
    }

    void pop()
    {
        arr[it--] = false;
    }

    int size()
    {
        return it + 1;
    }

    int is(int n)
    {
        return arr[n];
    }
};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    isStack ans;
    ans.init();

    for (int i = 0; i < n; i++)
    {
        int temp;

        cin >> temp;

        if (temp != 0)
            ans.push(temp);
        else
            ans.pop();
    }

    int sum = 0;

    for (int i = 0; i < ans.size(); i++)
        sum += ans.is(i);

    cout << sum;

    return 0;
}
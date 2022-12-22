#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> stack;

    for (int i = 0; i < n; i++)
    {
        string order;
        int temp;
        cin >> order;

        if (order == "push")
        {
            cin >> temp;
            stack.push_back(temp);
        }
        else if (order == "top")
        {
            if (!stack.empty())
                temp = stack.back();
            else
                temp = -1;
            cout << temp << "\n";
        }
        else if (order == "size")
        {
            cout << stack.size() << "\n";
        }
        else if (order == "empty")
        {
            if (stack.empty())
                temp = 1;
            else
                temp = 0;

            cout << temp << "\n";
        }
        else if (order == "pop")
        {
            if (!stack.empty())
            {
                temp = stack.back();
                stack.pop_back();
            }
            else
            {
                temp = -1;
            }

            cout << temp << "\n";
        }
    }

    return 0;
}
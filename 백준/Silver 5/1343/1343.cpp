#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string input, result;
    int count = 0;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input.at(i) == 'X')
            count++;

        if (i == input.length() - 1 || input.at(i) == '.')
        {
            if (count % 2 != 0)
                break;
            else
            {
                while (count > 0)
                {
                    if (count >= 4)
                    {
                        result += "AAAA";
                        count -= 4;
                    }
                    else if (count >= 2)
                    {
                        result += "BB";
                        count -= 2;
                    }
                }
            }

            if (input.at(i) == '.')
                result += ".";
        }
    }

    if (count % 2 == 1)
        cout << "-1";
    else
        cout << result;

    return 0;
}
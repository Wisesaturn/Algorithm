#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    int answer = 1;

    cin >> input;
    if (input.length() > 4 || input.length() < 0)
        return -1;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'd')
        {
            if (input[i] == input[i + 1])
                answer *= 9;
            else
                answer *= 10;
        }
        else
        {
            if (input[i] == input[i + 1])
                answer *= 25;
            else
                answer *= 26;
        }
    }

    cout << answer;
    return 0;
}
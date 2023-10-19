#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(int n)
{
    vector<string> dp;

    dp.push_back("0");
    dp.push_back("1");

    for (int i = 2; i <= 40; i++)
    {
        string prevState = dp[i - 1];
        string choiceNum = "";
        string result = "";
        int numCount = 0;

        for (int j = 0; j < prevState.length(); j++)
        {
            if (choiceNum.empty())
            {
                numCount++;
                choiceNum = prevState[j];
            }
            else if (!choiceNum.empty() && prevState[j] == choiceNum[0])
            {
                numCount++;
            }
            else if (!choiceNum.empty() && prevState[j] != choiceNum[0])
            {
                result += choiceNum[0];
                result += to_string(numCount);
                numCount = 1;
                choiceNum = prevState[j];
            }
        }
        result += choiceNum[0];
        result += to_string(numCount);
        dp.push_back(result);
    }

    return dp[n];
}
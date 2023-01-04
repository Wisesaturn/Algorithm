#include <string>

using namespace std;

string solution(string phone_number)
{
    string ans;
    for (int i = 0; i < phone_number.size() - 4; i++)
        ans += "*";
    return ans.append(phone_number.substr(phone_number.size() - 4));
}
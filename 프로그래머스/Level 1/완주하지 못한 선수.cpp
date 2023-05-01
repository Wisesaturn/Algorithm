#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    vector<string>::iterator it1 = participant.begin();
    vector<string>::iterator it2 = completion.begin();
    
    string ans = "";
    
    if (participant.size() == 1 && completion.size() == 0)
        return participant.back();
    
    while (*it1 == *it2) {
        it1++;
        it2++;
    }
    
    if (*it1 == participant.back()) {
        ans = participant.back();
    } else {
        ans = *it1;
    }
    
    return ans;
}

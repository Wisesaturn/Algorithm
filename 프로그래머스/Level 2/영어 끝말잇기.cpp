#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> ans;
    unordered_map<string, bool> checked;
    int turn = 0;
    int order = 0;
    int isFailed = 0;
    
    for (int i = 0 ; i < words.size() ; i++) {
        turn = i % n;
        
        if (turn == 0)
            order++;
        
        if (checked[words[i]]) {
            isFailed = turn + 1;
            break;
        }
        
        if (i > 0 && words[i - 1].back() != words[i].front()) {
            isFailed = turn + 1;
            break;
        }
        
        checked[words[i]] = true;
    }
    
    if (isFailed == 0)
        order = 0;
    
    ans.push_back(isFailed);
    ans.push_back(order);
    
    return ans;
}

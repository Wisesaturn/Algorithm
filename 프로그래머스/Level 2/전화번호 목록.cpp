#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    unordered_map<string, bool> checked;
    string tmp = "";
    
    for (string num : phone_book) {
        for (int i = 0 ; i < num.size(); i++) {
            tmp += num[i];
            
            if (!checked[tmp])
                continue;
                        
            return false;
        }
        
        checked[num] = true;
        tmp = "";
    }
    
    return true;
}

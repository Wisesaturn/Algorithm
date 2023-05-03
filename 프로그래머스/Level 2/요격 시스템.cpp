#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// greedy

int solution(vector<vector<int>> targets) {
    int cnt = 0;
    int prev_end = -1;
    
    sort(targets.begin(), targets.end(), [](const vector<int> a, const vector<int> b){
        return a[1] < b[1];
    });
    
    for (const vector<int> target : targets) {
        int start = target[0];
        int end = target[1];
                      
        if (prev_end >= end || start < prev_end)
            continue;
        
        prev_end = end;
        cnt++;
    }
    
    return cnt;
}

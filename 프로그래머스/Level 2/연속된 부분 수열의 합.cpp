#include <string>
#include <vector>
#include <iostream>

using namespace std;

// sliding window

vector<int> solution(vector<int> sequence, int k) {
    vector<int> ans(2);
    int sum = sequence[0];
    int start = 0;
    int end = 0;
    int len = sequence.size();
    
    while (end >= start && end < sequence.size()) {
        if (sum < k)
            sum += sequence[++end];
        else {
            if (sum == k) {
                if (end - start < len) {
                    len = end - start;
                    ans[0] = start;
                    ans[1] = end;
                } else if (end - start == len) {
                    if (start < ans[0]) {
                        ans[0] = start;
                        ans[1] = end;
                    }
                }
            }
            
            sum -= sequence[start++];
        }
        
        // cout << sum << " " << start << " " << end << endl;
    }
    
    return ans;
}
    
//  // window size
//     for (int i = 1 ; i <= sequence.size(); i++) {
//         int sum = 0;
        
//         for (int j = i - 1 ; j < prefixSum.size(); j++) {
//             if (j == i - 1)
//                 sum = prefixSum[j];
//             else 
//                 sum = prefixSum[j] - prefixSum[j - i];
                
//             if (sum == k) {
//                 ans[1] = j;
//                 ans[0] = j - i + 1;
//                 return ans;
//             }
//         }
//     }
    
//     // prefix sum
//     for (int i = 1 ; i < sequence.size(); i++) {
//         prefixSum[i] = prefixSum[i - 1] + sequence[i];
//     }
    
//     while (sum != k) {
//         if (sum < k || end <= start)
//             end++;
//         else if (sum > k)
//             start++;
        
//         if (start == end || start == -1)
//             sum = prefixSum[end];
//         else
//             sum = prefixSum[end] - prefixSum[start];
//     }
    
//     ans[0] = (start == -1) ? 0 : start + 1;
//     ans[1] = end;
    
//     return ans;
// }

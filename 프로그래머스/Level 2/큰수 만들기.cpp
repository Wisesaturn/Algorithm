#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string ans = "";
    int cnt = 0;
    int window_start = 0;
    int window_end = k;
    
    // 가장 큰 자릿수부터 차례대로 체크
    // 제일 큰 수를 큰 자릿수에 넣는다
    // 수를 찾기 위한 범위를 자릿수마타 세팅한다
    
    while (cnt < number.size() - k) {
        int biggest = -1;
        char biggest_element = '0';
        for (int i = window_start ; i <= window_end ; i++) {
            if (biggest_element < number[i]) {
                biggest = i;
                biggest_element = number[i];
            }
        }
        
        ans += biggest_element;
        cnt++;
        window_start = biggest + 1;
        window_end++;
        
    }
    
    return ans;
}

// Since 2022-01-03
// 문제 설명 : https://programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string new_id) {
    // 1. 대문자 -> 소문자
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    return new_id;
}
// 기본 템플릿을 만들어두었습니다.
// 이 파일을 복사하여 빠르게 풀어봅시다.

// ※ 딜레이 줄이기
// 1. endl보단 \n으로 개행 진행할 것
// 2. ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL) 이용
// 3. int보단 long long
// 4. 2차원 벡터보단 vector<int> tmp[] = {}으로, unordered_map보단 bool visited[]으로 시간단축이 가능

// ※ 배열 초기화 할 때
// 3-1. (0 또는 -1) memset(&cout, 0, sizeof(cout)); // include <cstring>
// 3-2. (그 이외) fill(&arr[0][0], &arr[max -1][max], val);
// 3-3. vector라면 기본값을 주거나 resize로 초기화할 것

// ※ 범위 내에서 index가 순차적으로 변화할 때
// 1. 나머지로 표현하기 -> 4가지 방향을 정리할 때 index를 하나씩 +/-를 한다면?
// (ex) (dir[j] + 1) % 4

// ※ C++ STL 중요한 것 정리
// 1. set (Node BST 구조, Red-Black Tree의 형태, 원소 자동 정렬)
//   1-1. insert, erase를 통해 node를 추가, 삭제할 수 있음
//   1-2. iterator로 값을 순회하면서 찾아야 함 (find를 통해 값 유무 알 수 있음)
// 2. map (key,value BST 구조, Red-Black Tree의 형태, key 기준 자동 정렬)
//   2-1. insert, erase를 통해 추가, 삭제가 가능함
//   2-2. iterator로 first, second 구문을 통해 key, value 확인 가능
//   2-3. find 구문을 통해 key를 통한 value 여부 확인 가능
// 3. unordered_map (key의 hash값에 따라 value를 저장)
// 4. erase + remove_if (C++ 20 이상엔 erase_if를 쓰는데 이건 코테에서 못 쓰므로 생략)
//    - vector 내에서 특정 조건을 가진 원소를 삭제할 수 있다
//    - ex) vector.erase(remove_if(vector.begin(), vector.end, [](int a){ return a == 2;}));

// ※ compare 비교 연산 함수 커스텀
// [priority_queue]
// struct compare
// {
//     bool operator()(const Node &a, const Node &b)
//     {
//         return a.cost < b.cost;
//     }
// };

// [sort]
// bool compare(Node a, Node b) {
// if (a.second == b.second)
//     return a.first < b.first;
// return a.second < b.second;
// }

// ※ 문자열 다룰 때
// string to int
//   string test = "12345 test"
//   int output;

// 정규식을 활용하면 쉽게 문자열을 바꿀 수 있다.
// #include <regex> 필요
// regex_replace(string, 정규식, 바꿀 문자열);
// ex) regex_replace(s, regex("three"), "3");

// 1. stringstream 이용
//   #include <sstream>
//   stringstream ss(원하는 string 값) ex) stringstring ss(s), s = "test";
//   ss >> output; (stringstream은 공백으로 구분, 뒤에는 다른 변수가 와도 무방)
//   string이 공백으로 구분 될 때, split()할 수 있음

// 2. stoi 이용
//   long long이면 stoll 사용
//   output = stoi(test);

// char to int
//   문자열을 빼서 사용
//   char num = '3';
//   int output = num - '0';

// int to string
//   to_string 사용 (#include <string> 필요)
//   int wow = 1234;
//   output = to_string(wow);

// 대소문자 구분할 때
//  아스키코드 상으로 A가 a보다 먼저 앞에 있다는 점 주의
// tolower(string), toupper(string)으로 쉽게 바꿀 수 있다.
// 대소문자 찾을 때 if (string[i] >= 'a' && string[i] <= 'z')를 이용하면 소문자 구분이 가능!
// ********************************

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}
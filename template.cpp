// 기본 템플릿을 만들어두었습니다.
// 이 파일을 복사하여 빠르게 풀어봅시다.

// ※ 딜레이 줄이기
// 1. endl보단 \n으로 개행 진행할 것
// 2. ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL) 이용
// 3. int보단 long long

// ※ 배열 초기화 할 때
// 3-1. (0 또는 -1) memset(&cout, 0, sizeof(cout)); // include <cstring>
// 3-2. (그 이외) fill(&arr[0][0], &arr[max -1][max], val);
// 3-3. vector라면 기본값을 주거나 resize로 초기화할 것

// ※ C++ STL 중요한 것 정리
// 1. set (Node BST 구조, Red-Black Tree의 형태, 원소 자동 정렬)
//   1-1. insert, erase를 통해 node를 추가, 삭제할 수 있음
// 2. map (key,value BST 구조, Red-Black Tree의 형태, key 기준 자동 정렬)
//   2-1. insert, erase를 통해 추가, 삭제가 가능함
//   2-2. iterator로 first, second 구문을 통해 key, value 확인 가능
//   2-3. find 구문을 통해 key를 통한 value 여부 확인 가능
// 3. unordered_map (key의 hash값에 따라 value를 저장)
// ********************************

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}
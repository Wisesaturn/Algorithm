// 기본 템플릿을 만들어두었습니다.
// 이 파일을 복사하여 빠르게 풀어봅시다.

// ※ 딜레이 줄이기
// 1. endl보단 \n으로 개행 진행할 것
// 2. ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL) 이용
// 3. int보단 long long

// ※ 배열 초기화 할 때
// 3-1. (0 또는 -1) memset(&cout, 0, sizeof(cout));
// 3-2. (그 이외) fill(&arr[0][0], &arr[max -1][max], val);
// ********************************

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}
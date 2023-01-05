#include <string>
#include <regex>

using namespace std;

bool solution(string s)
{
    regex pattern("^[0-9]{4}$|^[0-9]{6}$");
    // 네자리 숫자이거나 여섯자리 숫자일 때 (정규 표현)
    return regex_match(s, pattern);
}

// bool solution(string s)
// {
//     if (s.length() != 4 && s.length() != 6)
//         return false;

//     for (char c : s)
//         if (!isdigit(c))
//             return false;
//     return true;
// }
// isdigit 함수로 구현
// regex(정규 표현식)은 생각보다 속도가 느림
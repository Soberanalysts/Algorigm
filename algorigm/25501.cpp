#include<bits/stdc++.h>

using namespace std;

int T;              //테스트 수
string S;           //판별할 문자
int callCount;      //호출 횟수(변수 명을 count로 하면 표준라이브러리와 변수명 충돌하여 모호하다는 에러 발생)

int recursion(const char* s, int l, int r) {
    callCount++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1); 
    
}

int isPalindrome(const char* s) {
    callCount = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> S;

        int result = isPalindrome(S.c_str());
        //S.c_str() :  string 객체를 C 스타일 문자열(예: const char*)로 변환
        cout << result << ' ' << callCount<<'\n';
    }

}
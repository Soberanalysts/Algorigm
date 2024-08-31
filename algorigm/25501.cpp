#include<bits/stdc++.h>

using namespace std;

int T;              //�׽�Ʈ ��
string S;           //�Ǻ��� ����
int callCount;      //ȣ�� Ƚ��(���� ���� count�� �ϸ� ǥ�ض��̺귯���� ������ �浹�Ͽ� ��ȣ�ϴٴ� ���� �߻�)

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
        //S.c_str() :  string ��ü�� C ��Ÿ�� ���ڿ�(��: const char*)�� ��ȯ
        cout << result << ' ' << callCount<<'\n';
    }

}
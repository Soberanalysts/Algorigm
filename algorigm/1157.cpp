#include<bits/stdc++.h>

using namespace std;

//bool Inverse(int i, int j) {
//    return i > j;
//}

//int main() {
//	string input = "";
//    int count[26] = {};
//    int index = 0;
//    char letter;
//    cin >> input;
//
//    for (char c : input) {
//        if ((int)c >= 65 && (int)c <= 90) {
//            count[(int)(c - 65)]++;
//        }
//        else if ((int)c >= 97 && (int)c <= 122){
//            count[(int)(c - 97)]++;
//        }
//    }
//    vector<int> v_count(count, count + 26);
//    sort(v_count.begin(), v_count.end(), Inverse);
//    if (v_count[0] == v_count[1]) {
//        cout << '?';
//    } else {
//        for (int i = 0; i < 26; i++) {
//            if (count[i]==v_count[0]) {
//                index = i;
//                letter = (char)(index + 65);
//            }
//        }
//        cout << letter;
//    }
//}
int main() {
    string input;
    int count[26] = {};
    cin >> input;

    for (char c : input) {
        c = toupper(c);  // 대소문자 통일
        count[c - 'A']++;
    }

    int maxCount = 0;
    char result = '?';
    for (int i = 0; i < 26; ++i) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = 'A' + i;
        }
        else if (count[i] == maxCount) {
            result = '?';
        }
    }

    cout << result;
}
#include <unordered_map>
#include <bits/stdc++.h>
#include <initializer_list>

using namespace std;


int main() {

    unordered_map<string, int> um;

    if (um.empty()) {
        cout << "unordered_map�� ����ֽ��ϴ�" << endl;
    }
    um.insert(make_pair("key", 1));
    um["banana"] = 2;
    um.insert({ "melon",3});

    cout << "unordered_map�� ũ���" << um.size()<<"�Դϴ�"<<endl;

    cout << "endl";

    cout << "\n";


    //auto A { 1};

    //cout << A << endl;

    int count=10;
    int& countRef = count;
    auto myAuto = countRef;

    countRef = 11;
    cout << count << " ";

    myAuto = 12;
    cout << "\nmyauto\n";
    cout << count <<  endl;


    return 0;
}
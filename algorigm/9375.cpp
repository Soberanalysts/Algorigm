#include<bits/stdc++.h>

using namespace std;

int T, n;		//�׽�Ʈ ���̽�, �ǻ��� ��
string cloth, type_cloth;	//�ǻ��, �ǻ�����
vector<string> wear[2];

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cloth >> type_cloth;
			wear[0].push_back(cloth);
			wear[1].push_back(type_cloth);
		}
	}

}
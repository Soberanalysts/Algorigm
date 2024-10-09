#include<bits/stdc++.h>

using namespace std;

int T, n;		//테스트 케이스, 의상의 수
string cloth, type_cloth;	//의상명, 의상종류
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
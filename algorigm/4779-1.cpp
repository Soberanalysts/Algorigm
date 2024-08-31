//#include<bits/stdc++.h>
//
//using namespace std;

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int countrecur;

void CantorElim(string& sec, int start, int length) {
	countrecur++;
	if (length == 0) {
		return;
	}

	int length_semi = length / 3;
	int mid = start + length_semi;

	for (int i = mid; i < mid + length_semi; i++) {
		sec[i] = ' ';
	}

	CantorElim(sec, start, length_semi);
	CantorElim(sec, mid + length_semi, length_semi);
}

int main() {

	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int cnt, cnt_sup;
	string Cantor;

	while (cin >> cnt_sup) {

		cnt = pow(3, cnt_sup);
		Cantor.assign(cnt, '-');
		CantorElim(Cantor, 0, cnt);
		cout << Cantor << endl;

	}


	return 0;
}
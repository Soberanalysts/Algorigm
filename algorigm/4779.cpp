#include<bits/stdc++.h>

using namespace std;

int N;		//입력
string S;


//
//int Cantor(int n) {
//	for (int i = (n / 3); i < (2 * n / 3); i++)
//	{
//		S[i] = ' ';
//	}
//	for (int i = (2 * n / 3); i < n; i++)
//	{
//		S[i] = ' ';
//	}
//	//if (n == 0) return "-";
//	if (n == 1|| n==0 )return 0;
//	else { 
//		Cantor(n / 3);
//		//Cantor((2 * n) / 3);
//	}
//}
//
//
//int main() {
//
//	cin >> N;
//	int length=0;
//	length = pow(3, N);
//	S.resize(length);			//S가 length 문자를 수용할 만큼 충분히 큰지 확인
//	fill(S.begin(), S.begin() + length, '-');
//	Cantor(length);
//
//	cout << S;
//	//for (int i = 0; ) {
//	//	if (S[i] == 1) {
//	//		cout << '-';
//	//	}
//	//	else
//	//	{
//	//		cout << ' ';
//	//	}
//	//}
//
//}

void cantor(int n) {
	int size = pow(3, n - 1);

	// N = 0 인 경우 "-" 출력
	if (n == 0) {
		cout << "-";
		return;
	}

	// N번째 칸토어 집합 = N -1 번째 칸토어 집합을 2개 이은 것
	// 사이에 공백이 N - 1번째 칸토어 집합의 사이즈만큼 있어야 함
	cantor(n - 1);
	for (int i = 0; i < size; i++) {
		cout << " ";
	}
	cantor(n - 1);

}

int main() {


	while (cin >> N) {
		cantor(N);
		cout << "\n";
	}

	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int N;				//재귀횟수
string state1, state2, state3, state4, state5;
int recurFlag;		//재귀 순번
string underBar="";

void recur(int n) {
	if (n == 0) {
		return;
	}



	cout << '\n' << underBar + state1 << '\n' << underBar + state2 << '\n' << underBar + state3 << '\n' << underBar + state4;
	underBar += "____";
	recurFlag++;
	recur(n - 1);
	cout << '\n' << underBar + state5;
}
//void recur2(int n) {
//		if (n == 0) {
//		return;
//		}
//
//
//		underBar = underBar.substr(4 * (n-1));
//		
//		if ((n - 1) == 0) {
//			underBar = "";
//		}
//		
//
//		recur2(n - 1);
//	
//}

int main() {

	cin >> N;
	state1 = "\"재귀함수가 뭔가요 ?\"";
	state2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
	state3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
	state4 = "그의 답은 대부분 옳았다고 하네.그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
	state5 = "라고 답변하였지.";

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";

	recur(N);
	//recur2(N);
	//for (int i = recurFlag-1; i > 0; i--) {
	//	
	//	underBar= underBar.substr(4*i);
	//	if (i == 0) {
	//		underBar = "";
	//	}
	//	cout << '\n' << underBar + state5;
	//}
	//cout << '\n' << state5;

	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int N;				//���Ƚ��
string state1, state2, state3, state4, state5;
int recurFlag;		//��� ����
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
	state1 = "\"����Լ��� ������ ?\"";
	state2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
	state3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
	state4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�.�׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
	state5 = "��� �亯�Ͽ���.";

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.";

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

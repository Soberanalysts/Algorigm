//#include<bits/stdc++.h>
//
//using namespace std;
//
//int M, N;       //
//
//int main() {
//	fprintf(stdout,"Hellow error");
//	return 0;
//}
	#include <stdio.h>

	int func() {
		static int x = 0;	//static 변수는 한 번만 초기화되고, 함수가 끝나도 값을 유지
		x += 2;
		return x;
	}
	//2 4 6 8
	int main() {
		int x = 1;
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			x++;
			sum += func();	//2만 더해짐
		}
		printf("%d", sum);
		return 0;
	}
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int N;
//
//int fibo(int n) {
//
//	if (n == 0) {
//		return 0;
//	}
//	else if (n == 1) {
//		return 1;
//	}
//	else return fibo(n - 1) + fibo(n - 2);
//
//}
//
//
//int main() {
//	clock_t start, finish;
//	double duration;
//
//	start = clock();
//
//
//	cin >> N;
//
//	cout<< fibo(N);
//	/*실행 시간을 측정하고 싶은 코드*/
//
//	finish = clock();
//
//	duration = (double)(finish - start) / CLOCKS_PER_SEC;
//	cout << duration << "초" << endl;
//}

#include <bits/stdc++.h>

using namespace std;

long long dp[91], n;

long long fibo(long long idx) {
	if (idx == 0 || idx == 1) return idx;
	long long& ret = dp[idx];
	if (ret) return ret;
	return ret = fibo(idx - 1) + fibo(idx - 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cout << fibo(n) << '\n';

	return 0;
}


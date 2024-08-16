//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int N, K;
//
//	cin >> N >> K;
//	int ans = 0;
//	for (int h = 0; h <= min(N, 23); h++)
//		for (int m = 0; m <= 59; ++m)
//			for (int s = 0; s <= 59; ++s)
//				if ((h % 10 == K || h / 10 == K)|| (m % 10 == K || m / 10 == K) || (s % 10 == K || s / 10 == K))
//					ans++;
//	cout << ans;
//		
//	return 0;
//}
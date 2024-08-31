#include <bits/stdc++.h>

using namespace std;

long dp[1001],result;
int n;						//채울 직사각형 가로 길이


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	dp[1] = 1, dp[2] = 3;

	cin >> n;		
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + (2 * dp[i - 2]);
	}
	result = dp[n] % 10007;
	cout << result;

	return 0;
}
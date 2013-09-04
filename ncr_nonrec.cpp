#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[100][100];
bool memo[100][100];

int ncr_dp(int N) {
	for (int i=1 ; i<=N ; i++) {
		for (int j=1 ; j<=N ; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
}

int main() {

	int N = 100;

	for (int i=0 ; i<N ; i++) { // Any number taken 0 times
		dp[i][0] = 1;
		memo[i][0] = true;
	}
	for (int i=1 ; i<N ; i++) { // 0 taken > 0 times
		dp[0][i] = 0;
		memo[0][i] = true;
	}
	ncr_dp(42);

	cout << dp[32][19] << endl;

	return 0;
}
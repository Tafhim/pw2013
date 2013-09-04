#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[100][100];
bool memo[100][100];

int ncr_memo(int n, int r) {
	if (memo[n][r]==true) return dp[n][r]; // The result was calculated earlier
	dp[n][r] = ncr_memo(n-1,r-1) + ncr_memo(n-1,r); // Calculate the result
	memo[n][r] = true; // Mark it done for future
	return dp[n][r];
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

	cout << ncr_memo(24,16) << endl;

	return 0;
}
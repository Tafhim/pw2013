#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000], p[1000];
int main() {

	int sequence[] = {5, 2, 3, 4, 6, 7, 1, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, mx=0;
	vector<int> seq (sequence, sequence + (sizeof(sequence)/sizeof(int)));

	for (int i=0 ; i<seq.size() ; i++) {
		dp[i] = 1;
		p[i] = -1;
		for (int j=0 ; j<i ; j++) {
			if (seq[j] < seq[i]) {
				if (dp[i] < dp[j]+1) {
					dp[i] = dp[j]+1;
					p[i] = j;
				}
			}
		}
		if (dp[mx] < dp[i]) mx = i;
	}

	for (int i=mx ; i>=0 ; i=p[i]) {
		cout << seq[i] << " ";
	}
	cout << endl;

	return 0;
}
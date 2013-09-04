#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define UP 0
#define DOWN 1

int dp[100][2];
int p[100];

int main() {

	int sequence[] = {5, 2, 3, 4, 6, 7, 1, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, mx=0, my=0;
	vector<int> seq (sequence, sequence + (sizeof(sequence)/sizeof(int)));

	for (int i=0 ; i<seq.size() ; i++) {
		dp[i][UP] = dp[i][DOWN] = 1;
		p[i] = -1;
		for (int j=0 ; j<i ; j++) {
			if (seq[i]-seq[j] > 0) {
				//dp[i][UP] = max(dp[j][DOWN]+1, dp[i][UP]);
				if (dp[j][DOWN]+1 > dp[i][UP]) {
					dp[i][UP] = dp[j][DOWN]+1;
					p[i] = j;
				}
			} else if (seq[i]-seq[j] < 0) {
				//dp[i][DOWN] = max(dp[i][UP]+1, dp[i][DOWN]);
				if (dp[j][UP]+1 > dp[i][DOWN]) {
					dp[i][DOWN] = dp[j][UP]+1;
					p[i] = j;
				}
			}
		}
		if (dp[i][UP] > dp[mx][UP]) {
			if (dp[i][UP] > dp[mx][DOWN]) {
				mx = i;
			}
		} else if (dp[i][DOWN] > dp[mx][DOWN]) {
			if (dp[i][DOWN] > dp[mx][DOWN]) {
				mx = i;
			}
		}
	}

	for (int x = mx ; x>=0 ; x=p[x]) {
		cout << seq[x] << " ";
	}
	cout << endl;

	return 0;
}
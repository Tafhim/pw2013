#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int combis[100][100];

int no_memo_ncr(int n, int r) {
	/*
		nCr = (n-1)C(r-1) + (n-1)Cr
	*/
	if (r==0) return 1; // Any number of items taken 0 times
	if (n==0) return 0; // 0 items taken >0 times

	return no_memo_ncr(n-1,r-1) + no_memo_ncr(n-1,r);
}


int main() {
	cout << no_memo_ncr(0,2) << endl;
	return 0;
}
/*
 * Uva 12908 - The book thief
 * author: roy4801
 * AC(C++) 0.130
 */
#include <iostream>

using namespace std;

#define N 15000

int ps[N+5];

// 1-index
int binarySearch(int start, int end, int val)
{
	if(end - start == 1)
		return start;
		// return ps[start] == val ? start : N+1;

	int mid = (start+end) / 2;
	if(ps[mid] > val)
		return binarySearch(start, mid, val);
	else
		return binarySearch(mid, end, val);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12908.in", "r", stdin);
	freopen("./testdata/12908.out", "w", stdout);
	#endif
	// Init ps[]
	for(int i = 1; i <= N; i++)
		ps[i] = ps[i-1] + i;

	int in;

	while(scanf("%d", &in) != EOF && in)
	{
		int n = binarySearch(1, N, in) + 1;
		printf("%d %d\n", (n*n + n) / 2 - in, n);
	}

	return 0;
}
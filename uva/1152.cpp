/*
 * UVA 1152 - Values whose Sum is 0
 * author: roy4801
 * AC(C++) 4.950
 */
// #hash_table
#include <bits/stdc++.h>

using namespace std;

#define PROB "1152"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef unordered_map<int, int> UM;
#define N 4000

UM um;
int A[N], B[N], C[N], D[N];
int fir[N][N];
int n;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int cases;
	bool print = false;
	cin >> cases;
	while(cases-- && cin >> n)
	{
		um.clear();
		int cnt = 0;
		// input
		for(int i = 0; i < n && cin >> A[i] >> B[i] >> C[i] >> D[i]; i++);
		//
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				fir[i][j] = A[i] + B[j];
				if(um.count(C[i] + D[j]))
				{
					um[C[i] + D[j]]++;
				}
				else
					um.insert(make_pair(C[i] + D[j], 1));
			}
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				// printf("i=%d,j=%d %d + %d ", i, j, A[i], B[j]);
				if(um.count(-fir[i][j]))
				{
					cnt += um[-fir[i][j]];
				}
			}

		if(print)
			putchar('\n');
		cout << cnt << '\n';

		print = true;
	}
	return 0;
}
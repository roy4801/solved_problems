/*
 * UVA 1152 - Values whose Sum is 0
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1152"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 4000

int A[N], B[N], C[N], D[N];
int fir[N][N], sec[N][N];
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
		if(print)
			putchar('\n');
		int cnt = 0;
		for(int i = 0; i < n && cin >> A[i] >> B[i] >> C[i] >> D[i]; i++);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				fir[i][j] = A[i] + B[j];
				sec[i][j] = C[i] + D[j];
			}
			sort(fir[i], fir[i] + n);
			sort(sec[i], sec[i] + n);
		}

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
				{
					int p = lower_bound(sec[k], sec[k]+n, -fir[i][j]) - sec[k];

					if(p < n && fir[i][j] + sec[k][p] == 0)
					{
						cnt++;
					}
				}
		cout << cnt << '\n';
		print = true;
	}
	return 0;
}
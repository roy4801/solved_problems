/*
 * UVA 400 - Unix ls
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "400"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 100
string v[N+5];
int n, maxlen, col, row;
char fmt[64];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		maxlen = 0;
		//
		for(int i = 0; i < n && cin >> v[i]; i++);
		sort(v, v+n);

		// for(int i = 0; i < n; i++)
		// 	cout << v[i] << '\n';

		for(int i = 0; i < n; i++)
			if(maxlen < v[i].size()) maxlen = v[i].size();
		for(int i = 0; i < 60; i++) putchar('-');
		puts("");

		col = 1 + (60 - maxlen) / (maxlen+2);
		if(!col) col = 1;
		row = ceil(n / (double)col);
		// printf("%d %d\n", row, col);
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				sprintf(fmt, "%%-%ds", j != col-1 ? maxlen+2 : maxlen);
				if(j*row + i < n)
					printf(fmt, v[j*row + i].c_str());
			}
			puts("");
		}
		END:
		;
		// puts("");
	}
	return 0;
}
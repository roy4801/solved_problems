/*
 * UVA 1619 - Feel Good
 * author: roy4801
 * (C++)
 */
// #rewrite #mul_ans #WA
#include <bits/stdc++.h>

using namespace std;

#define PROB "1619"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
#define N 100000

LL val[N+5], sum[N+5];
int L[N+5], R[N+5];
int n;
int idx;
#define CALC(x) (val[x]*(sum[R[x]]-sum[L[x]-1]))

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	bool pt = false;
	while(cin >> n)
	{
		memset(val, 0, sizeof(val));
		memset(sum, 0, sizeof(sum));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		// val[0] = val[n+1] = 0;
		//
		for(int i = 1; i <= n && cin >> val[i]; i++)
		{
			sum[i] = sum[i-1] + val[i];
			L[i] = R[i] = i;
		}

		for(int i = 1; i <= n; i++)
			while(val[L[i]-1] >= val[i] && L[i]-1 > 0)
				L[i] = L[ L[i]-1 ];

		for(int i = n; i >= 1; i--)
			while(val[R[i]+1] >= val[i] && R[i]+1 <= n)
				R[i] = R[ R[i]+1 ];

		LL maxx = -1;
		int ans_l, ans_r;
		for(int i = 1; i <= n; i++)
		{
			LL tmp = CALC(i);
			if(maxx < tmp)
			{
				maxx = tmp;
				// idx = i;
				ans_l = L[i];
				ans_r = R[i];
			}
		}

		if(pt)
			putchar('\n');
		cout << maxx << '\n';
		cout << ans_l << ' ' << ans_r << '\n';
		pt = true;
	}

	return 0;
}
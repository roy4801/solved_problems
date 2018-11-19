/*
 * UVA 11389 - The Bus Driver Problem
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11389"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 100
int n, d, r; // route, dis(mor + eve), pay per unit
int mor[N], eve[N];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n >> d >> r && (n && d && r))
	{
		int pay = 0;
		for(int i = 0; i < n && cin >> mor[i]; i++);
		for(int i = 0; i < n && cin >> eve[i]; i++);

		sort(mor, mor + n);
		sort(eve, eve + n, greater<int>());

		for(int i = 0; i < n; i++)
		{
			int dis = mor[i] + eve[i] - d;
			pay += (dis > 0 ? dis * r : 0);
		}
		cout << pay << '\n';
	}

	return 0;
}

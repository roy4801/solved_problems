/*
 * UVA 1610 - Party Games
 * author: roy4801
 * (C++)
 */
// #rewrite #string
#include <bits/stdc++.h>

using namespace std;

#define PROB "1610"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;

#define N 1000
string arr[N+5], le, ri;
int n;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n && n)
	{
		for(int i = 0; i < n && cin >> arr[i]; i++);

		sort(arr, arr+n);

		le = arr[(n/2)-1];
		ri = arr[n/2];

		string ans = "A";

		int i = 0, l = le.size();
		while(i < l)
		{
			while(ans[i] <= 'Z' && ans < le)
				ans[i]++;

			if(ans[i] <= 'Z' && ans >= le && ans < ri)
			{
				cout << ans << '\n';
				break;
			}

			if(ans[i] != le[i])
				ans[i]--;
			ans += 'A';
			i++;
		}
	}

	return 0;
}
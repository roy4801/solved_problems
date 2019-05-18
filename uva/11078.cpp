/*
 * UVA 11078 - Open Credit System
 * author: roy4801
 * AC(C++) 0.120
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11078"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define N 100000
int ka, n, in, maxv; // case, num stu, input, minimum
int d[N+5];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> ka;
	while(ka-- && cin >> n)
	{
		memset(d, 0, sizeof(d));
		maxv = INT_MIN;

		cin >> in;
		maxv = max(maxv, in);
		for(int i = 1; i < n && cin >> in; i++)
		{
			d[i] = maxv - in;
			maxv = max(maxv, in);
		}

		int res = INT_MIN;
		for_each(d+1, d+1+n-1, [&res](const int &i){ // [1, n)
			res = max(res, i);
		});
		cout << res << '\n';
	}
	return 0;
}

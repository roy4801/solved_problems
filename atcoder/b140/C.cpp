/*
 *  C - Maximal Value
 * author: roy4801
 * AC(C++) 0.001
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "C"
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
int n;
int b[N+5];
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		for(int i = 1; i <= n-1 && cin >> b[i]; i++);

		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
				sum += b[1];
			else if(i == n-1)
				sum += b[n-1];
			else
				sum += min(b[i], b[i+1]);
		}
		cout << sum << '\n';
	}

	return 0;
}
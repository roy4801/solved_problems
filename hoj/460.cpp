/*
 * HOJ 460 - 得分
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "460"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define N 10000
int kase;
int n, s; // score type, target score
LL dp[N+5];
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n >> s)
	{
		memset(dp, 0, sizeof(dp));

		dp[0] = 1;
		for(int i = 0, sc; i < n && cin >> sc; i++)
		{
			for(int j = sc; j <= s; j++)
			{
				dp[j] += dp[j - sc];
			}
		}

		cout << dp[s] << '\n';
	}

	return 0;
}

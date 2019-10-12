/*
 * UVA 11536 - Smallest Sub-Array
 * author: roy4801
 * AC(C++) 3.090
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11536"
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
#define N 1000000
#define K 100
int kase;
int n, m, k;
int arr[N+5], cnt[K+5], ans;
bool lDo; // left do
void init()
{
	for(int i = 1; i <= 3; i++) arr[i] = i;
	for(int i = 4; i <= n; i++) arr[i] = (arr[i-1]+arr[i-2]+arr[i-3]) % m + 1;
	memset(cnt, 0, sizeof(cnt));
	lDo = false;
	ans = INT_MAX;
}
inline bool check()
{
	int c = 0;
	for(int i = 1; i <= k; i++)
		if(cnt[i] > 0) c++;
	return c == k;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int T = 1;
	cin >> kase;
	while(kase-- && cin >> n >> m >> k)
	{
		init();
		//
		int l = 1, r = 1;
		while(r <= n)
		{
			while(r <= n) // move right ptr
			{
				if(arr[r] <= k)
					cnt[arr[r]]++;
				r++;
				if(check())
				{
					ans = min(ans, r-l);
					lDo = true;
					break;
				}
			}
			while(lDo && l <= n) // move left ptr
			{
				if(arr[l] <= k)
					cnt[arr[l]]--;
				l++;
				if(!check())
				{
					ans = min(ans, r-(l-1));
					lDo = false;
					break;
				}
			}
		}
		printf("Case %d: ", T++);
		if(ans != INT_MAX)
			printf("%d\n", ans);
		else
			puts("sequence nai");
	}
	return 0;
}
/*
 * HOJ 463 - 烤餅乾
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "463"
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
#define PPB pop_back
#define PF push_front
#define PPF pop_front
int kase;
int n, tmp, cnt;
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		cnt = 0;
		//
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				tmp = n-i-j;
				if(tmp <= 0) continue;
				if(i <= j && j <= tmp
				&& i + j > tmp && i - j < tmp)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}

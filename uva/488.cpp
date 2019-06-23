/*
 * UVA 488 - Triangle Wave
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "488"
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
int n, m, f;
bool fl;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	while(n-- && ~scanf("%d %d", &m, &f))
	{
		if(fl) putchar('\n');
		for(int i = 0; i < f; i++)
		{
			if(i != 0) putchar('\n');
			for(int j = 1; j <= m; j++)
			{
				for(int a = 0; a < j; a++)
					printf("%d", j);
				putchar('\n');
			}
			for(int j = m-1; j >= 1; j--)
			{
				for(int a = 0; a < j; a++)
					printf("%d", j);
				putchar('\n');
			}
		}
		fl = true;
	}

	return 0;
}
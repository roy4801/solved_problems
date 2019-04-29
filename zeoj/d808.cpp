/*
 * ZEOJ d808 - 黑暗部落
 * author: roy4801
 * AC(C++) 0.9
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "d808"
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

int n;
#define N 1000000
int p[N+5], size[N+5];
int grp;
void init()
{
    for(int i = 0; i <= N; i++)
    {
    	p[i] = i;
    	size[i] = 1;
    }
    grp = n;
}
int find(int x)
{
    return p[x] == x ? (p[x]) : (p[x] = find(p[x]));
}
void uni(int a, int b)
{
	a = find(a), b = find(b);
	if(a != b)
	{
		grp--;
	    p[a] = b;
	    size[b] += size[a];
	    size[a] = 0;
	}
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int to;
	while(cin >> n)
	{
		init();
		
		for(int i = 1; i <= n && cin >> to; i++)
			uni(i, to);

		// for(int i = 1; i <= n; i++)
		// 	printf("%d ", size[i]);
		// puts("");
		
		int ma = INT_MIN;
		for(int i = 1; i <= n; i++)
			if(size[i] > ma)
				ma = size[i];

		printf("%d %d\n", grp, ma);
	}

	return 0;
}

/*
 * LUOGU P1196 - [NOI2002]銀河英雄傳說
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "P1196"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 30000

int p[N], size[N];
void init() { for(int i = 0; i < N; i++) { p[i] = i; size[i] = 1; } }
int find(int x)
{
    return x==p[x] ? x : (p[x] = find(p[x]));
}
void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a == b) return;
    
    if(size[a] > size[b])
    {
        p[b] = a;
        size[a] += size[b];
    }
    else
    {
        p[a] = b;
        size[b] += a;
    }
}
int m;

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	char opt;
	int a, b;
	while(cin >> m)
	{
		init();
		while(m-- && cin >> opt >> a >> b)
		{
			a--, b--;
			if(opt == 'M')
			{
				uni(a, b);
			}
			else if(opt == 'C')
			{
				if(find(a) == find(b))
				{
					cout << size[a] << ' ' << size[b] << '\n';
				}
				else
					cout << -1 << '\n';
			}
		}
	}

	return 0;
}
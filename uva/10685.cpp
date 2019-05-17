/*
 * UVA 10685 - Nature
 * author: roy4801
 * AC(C++) 0.130
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10685"
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

int n, r;
string in, inb;

#define N 5000
map<string, int> m;
int mId = 1;

int p[N+5];
int siz[N+5];
void init()
{
	for(int i = 0; i <= N; i++)
	{
		p[i] = i;
		siz[i] = 1;
	}
}
int find(int x)
{
	return p[x]==x ? x : (p[x]=find(p[x]));
}
void uni(int a, int b)
{
	a = find(a), b = find(b);

	if(siz[a] > siz[b])
	{
		p[b] = a;
		siz[a] += siz[b];
		siz[b] = 0;
	}
	else
	{
		p[a] = b;
		siz[b] += siz[a];
		siz[a] = 0;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n >> r && (n || r))
	{
		init();
		m.clear();
		mId = 1;

		for(int i = 0; i < n && cin >> in; i++)
			if(!m.count(in))
				m[in] = mId++;

		for(int i = 0; i < r && cin >> in >> inb; i++)
		{
			int l = m[in], r = m[inb];
			if(find(l) != find(r))
			{
				uni(l, r);
			}
		}

		int maxv = INT_MIN;
		for_each(siz+1, siz+n+1, [&maxv](int i){ // 1-index
			maxv = max(maxv, i);
		});

		cout << maxv << '\n';
	}

	return 0;
}
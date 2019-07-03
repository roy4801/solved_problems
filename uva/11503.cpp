/*
 * UVA 11503 - Virtual Friends
 * author: roy4801
 * AC(C++) 0.350
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11503"
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
#define N 100000
int p[N+5], siz[N+5];
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
		p[b] = p[a];
		siz[a] += siz[b];
		siz[b] = 0;
	}
	else
	{
		p[a] = p[b];
		siz[b] += siz[a];
		siz[a] = 0;
	}
}
unordered_map<string, int> m;
int grp;
inline int getNum(string s)
{
	if(!m.count(s))
		m[s] = grp++;
	return m[s];
}
//
int kase, n;
string a, b;
int tmpa, tmpb;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		grp = 1;
		m.clear();
		init();
		//
		for(int i = 0; i < n && cin >> a >> b; i++)
		{
			tmpa = getNum(a); tmpb = getNum(b);
			if(find(tmpa) != find(tmpb))
				uni(tmpa, tmpb);
			printf("%d\n", siz[find(tmpa)]);
		}
	}
	return 0;
}
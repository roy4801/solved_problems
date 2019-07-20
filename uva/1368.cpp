/*
 * UVA 1368 - DNA Consensus String
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1368"
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
#define N 1000
string s, optim;
string v[N+5];
int cnt[N+5][4]; // s[i] [A|T|C|G]
int dnaToIdx[256];
int kase;
int m, n;
char pt[] = "ACGT";
inline void init()
{
	dnaToIdx['A'] = 0;
	dnaToIdx['C'] = 1;
	dnaToIdx['G'] = 2;
	dnaToIdx['T'] = 3;
}
int mi, mx;
inline int hamming(string &a, string &b)
{
	int c = 0;
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i]) c++;
	return c;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	init();
	cin >> kase;
	while(kase-- && cin >> m >> n)
	{
		memset(cnt, 0, sizeof(cnt));
		optim = "";
		mx = 0;

		for(int i = 0; i < m && cin >> s; i++)
		{
			v[i] = s;
			for(int j = 0; j < s.size(); j++)
				cnt[j][ dnaToIdx[s[j]] ]++;
		}

		for(int i = 0; i < n; i++)
		{
			mi = mx = 0;
			for(int j = 0; j < 4; j++)
				if(mx < cnt[i][j])
					mx = cnt[i][j], mi = j;
			optim += pt[mi];
		}

		mx = 0;
		for(int i = 0; i < m; i++)
			mx += hamming(optim, v[i]);
		
		printf("%s\n%d\n", optim.c_str(), mx);
	}
	return 0;
}
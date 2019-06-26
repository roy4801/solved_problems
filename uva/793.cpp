/*
 * UVA 793 - Network Connections
 * author: roy4801
 * AC(C++) 0.850
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "793"
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
#define N 10000000
int p[N+5];
void init()
{
	for(int i = 0; i <= N; i++) p[i] = i;
}
int find(int x)
{
	return x==p[x] ? x : (p[x]=find(p[x]));
}
void uni(int a, int b)
{
	p[find(a)] = find(b);
}
int kase, n, a, b;
char opt;
string in;
int succ, unsucc;
bool fl;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	while(kase-- && cin >> n)
	{
		init();
		succ = unsucc = 0;
		getchar();

		while(getline(cin, in) && in != "")
		{
			sscanf(in.c_str(), "%c %d %d", &opt, &a, &b);
			if(opt == 'c')
				uni(a, b);
			else if(opt == 'q')
			{
				if(find(a) == find(b))
					succ++;
				else
					unsucc++;
			}
		}
		fl && puts("");
		printf("%d,%d\n", succ, unsucc);
		fl = true;
	}

	return 0;
}

/*
 * UVA 1583 - Digit Generator
 * author: roy4801
 * AC(C++) 0.080
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1583"
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
vector<int> v[N+5];
inline int cal(int n)
{
	int tmp = 0;
	while(n)
	{
		tmp += n % 10;
		n /= 10;
	}
	return tmp;
}
void build()
{
	for(int i = 1; i <= N; i++)
	{
		int tmp = i + cal(i);
		if(tmp <= N)
			v[tmp].PB(i);
	}
}
int kase, n;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	build();
	cin >> kase;
	while(kase-- && cin >> n)
	{
		if(v[n].size())
			cout << v[n][0] << '\n';
		else
			cout << "0" << '\n';
	}
	return 0;
}
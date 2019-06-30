/*
 * UVA 11286 - Conformity
 * author: roy4801
 * AC(C++) 0.090
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11286"
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
int n, tmp;
map<string, int> m;
int v[5];
string s;
int mi, mv;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n && n)
	{
		mi = mv = 0;
		m.clear();

		for(int i = 0; i < n; i++)
		{
			s = "";
			memset(v, 0, sizeof(v));
			//
			for(int j = 0; j < 5 && cin >> tmp; j++)
				v[j] = tmp;
			sort(v, v+5);
			for(int j = 0; j < 5; j++)
				s += to_string(v[j]);

			m[s]++;
		}
		
		for(auto &x : m)
		{
			// cout << x.F << ' ' << x.S << '\n';
			if(x.S > mi)
			{
				mi = x.S;
				mv = 0;
			}
			if(x.S == mi)
				mv += mi;
		}
		cout << mv << '\n';
	}

	return 0;
}

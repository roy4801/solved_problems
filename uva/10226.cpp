/*
 * UVA 10226 - Hardwood Species
 * author: roy4801
 * AC(C++) 0.620
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10226"
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
int n;
string s;
map<string, int> m;
int total = 0;
bool fl;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> n; getchar(); getchar();
	while(n--)
	{
		m.clear();
		total = 0;

		while(getline(cin, s) && s != "")
		{
			if(!m.count(s))
			{
				m[s] = 1;
			}
			else
			{
				m[s]++;
			}
			total++;
		}

		if(fl) puts("");
		for(auto &i : m)
			printf("%s %.4lf\n", i.F.c_str(), i.S * 100.0 / (double)total);
		fl = true;
	}

	return 0;
}

/*
 * UVA 455 - Periodic Strings
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "455"
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
size_t h;
string s;
bool pass, pt;
hash<string> hg;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> n;
	while(n-- && cin >> s)
	{
		if(pt) puts("");
		for(int i = 1; i <= s.size(); i++) // len
		{
			pass = true;

			if(s.size() % i == 0)
			{
				h = hg(s.substr(0, i));
				for(int j = 1; j < s.size()/i; j++) // group by i
					if(h != hg(s.substr(i*j, i)))
						pass = false;

				if(pass)
				{
					printf("%d\n", i);
					break;
				}
			}
		}
		pt = true;
	}

	return 0;
}
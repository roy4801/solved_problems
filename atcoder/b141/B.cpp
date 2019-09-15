/*
 *  B - Tap Dance
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "B"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
string s;
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> s)
	{
		bool fail = false;
		for(int i = 0; i < s.size(); i++)
		{
			if((i+1) % 2 != 0) // odd
			{
				if(s[i] == 'L')
					fail = true;
			}
			else
			{
				if(s[i] == 'R')
					fail = true;
			}
			if(fail) break;
		}
		if(fail)
			puts("No");
		else
			puts("Yes");
	}

	return 0;
}
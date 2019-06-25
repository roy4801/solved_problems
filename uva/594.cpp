/*
 * UVA 594 - One Little, Two Little, Three Little Endians
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "594"
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
int n = 20034556;
int tmp;
char *to = (char*)&tmp, *fr = (char*)&n;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		for(int i = 0; i < 4; i++)
			to[i] = fr[3 - i];

		printf("%d converts to %d\n", n, tmp);
	}
	return 0;
}

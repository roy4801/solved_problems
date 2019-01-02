/*
 * UVA 10382 - Watering Grass
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10382"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<double, double> P;
#define F first
#define S second

#define N 10000
int n, l, w;
P cir[N]; // l, r

#define CALC(r) sqrt(pow((double)(r), 2) - pow((double)w, 2) / 4.0)

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int x, r;
	while(cin >> n >> l >> w)
	{
		for(int i = 0; i < n && cin >> x >> r; i++)
		{
			cir[i].F = x - CALC(r);
			cir[i].S = x + CALC(r);
		}
		
		sort(cir, cir + n);

		bool valid = true;
		auto cur = cir[0];
		for(int i = 1; i < n; i++)
		{
			if(cir[i] <= cur.S)
			{
				
			}
		}
	}

	return 0;
}
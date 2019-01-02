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
int size;
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
			double wid = CALC(r);
			if(!isnan(wid))
			{
				cir[i].F = x - wid;
				cir[i].S = x + wid;
				size++;
			}
		}
		
		sort(cir, cir + n);
		//
		for(int i = 0; i < n; i++)
			cout << fixed << setprecision(2) << cir[i].F << ' ' << cir[i].S << '\n';
		puts("------------------------------");
		//
		int le = 0, ri = 0;
		int cnt = 0;
		int stat = 0;
		bool pass;
		//
		int max = INT_MIN, mI;
		bool select = false;
		for(int i = 0; i < size;)
		{
			auto cur = cir[i];
			// start
			if(stat == 0)
			{
				if(cur.F <= le)
				{
					ri = cur.S;
					cnt++;
					stat = 1;
				}
			}
			else if(stat == 1) // mid
			{
				if(cur.F <= ri)
				{
					if(cur.S > max)
					{
						mI = i;
						select = true;
					}
				}
				else
				{
					if(select)
					{
						cnt++;
						ri = cir[mI].S;
						max = INT_MIN;
						select = false;
						continue;
					}
				}
			}
			i++;
		}
		
		if(le >= 0 && ri <= l)
			printf("%d\n", cnt);
		else
			puts("-1");
	}

	return 0;
}
/*
 * UVA 10382 - Watering Grass
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10382"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<double, double> P;
#define F first
#define S second

int n, l, w;
vector<P> cir; // l, r

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
		cir.clear();

		for(int i = 0; i < n && cin >> x >> r; i++)
		{
			double wid = CALC(r);
			// printf("x=%d r=%d wid=%.2lf\n", x, r, wid);
			// printf("l=%.2lf r=%.2lf\n\n", x - wid, x + wid);
			if(!isnan(wid))
			{
				cir.emplace_back(x - wid, x + wid);
			}
		}
		
		sort(cir.begin(), cir.end());
		//
		// for(int i = 0; i < cir.size(); i++)
		// 	cout << fixed << setprecision(2) << cir[i].F << ' ' << cir[i].S << '\n';
		// putchar('\n');
		//
		double le = 0, ri = 0;
		int cnt = 0;
		//
		for(int i = 0; i < cir.size();)
		{
			bool selected = false, step = true;
			// printf(">> le=%.2lf ri=%.2lf i=%d\n", le, ri, i);
			while(cir[i].F <= le && i < cir.size())
			{
				step = false;
				if(cir[i].S >= ri)
				{
					selected = true;
					ri = cir[i].S;
					// printf(">> IN %.2lf %.2lf i=%d\n", le, ri, i);
				}
				i++;
			}
			// counter
			if(selected)
				cnt++;
			if(step)
				i++;
			// jump out
			if(ri >= l)
				break;
			if(i >= cir.size() && ri < l)
				cnt = 0;

			le = ri;
		}
		printf("%d\n", cnt==0?-1:cnt);

	}

	return 0;
}
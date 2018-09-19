/*
 * Uva 10976 - Fractions Again?!
 * author: roy4801
 * AC(C++) 0.010
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10976.in", "r", stdin);
	freopen("./testdata/10976.out", "w", stdout);
	#endif
	int frac;

	while(scanf("%d", &frac) != EOF)
	{
		// int cnt = 1;
		vector<pair<int, int> > ans;

		ans.push_back(pair<int, int>(frac*(frac+1), frac+1));

		for(int i = frac+2; i <= frac*2; i++)
		{
			int bottom = frac * i;
			// printf("bottom: %d\n", bottom);

			if(__gcd(bottom, i - frac) != 1 && bottom % (i-frac) == 0)
			{
				int left = bottom / (i - frac);
				// cnt++;

				// printf("%d %d\n", left, i);
				ans.push_back(pair<int, int>(left, i));
			}
		}
		// printf("%d %d\n", frac*(frac+1), frac+1);
		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++)
		{
			printf(i != ans.size()-1 ? "1/%d = 1/%d + 1/%d\n" : "1/%d = 1/%d + 1/%d", frac, ans[i].first, ans[i].second);
		}

		putchar('\n');
	}

	return 0;
}
/*
 * Uva 11235 - Frequent values
 * author: roy4801
 * AC(C++) 1.340
 */
#include <bits/stdc++.h>

using namespace std;

// Normal method
// maintain three arrays: count for numbers, left border, and right border

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11235.in", "r", stdin);
	freopen("./testdata/11235.out", "w", stdout);
	#endif
	int len, query;

	while(scanf("%d %d", &len, &query) != EOF && len)
	{
		int n[len], prev, grp = 1;
		int idxToGrp[len];

		// input n[]
		for(int i = 0; i < len; i++)
		{
			scanf("%d", &n[i]);
			// not first and not in same group
			if(i && n[i] != prev)
				grp++;

			prev = n[i];
			idxToGrp[i] = grp-1;
		}

		//
		int cnt[grp] = {1}, cntIdx = 0; // count for number in groups
		int lBorder[len] = {0}, rBorder[len] = {0}; // left and right border
		int nowL = 0, nowR = len-1; // current l/r border in the group

		lBorder[0] = nowL;
		rBorder[len-1] = nowR;

		for(int i = 0; i < grp; i++) // init
			cnt[i] = 1;

		for(int i = 1, j = (len-1) - 1; i < len && j >= 0; i++, j--)
		{
			// Judge from left and count number in groups
			if(n[i] != n[i-1])
			{
				nowL = i;

				cntIdx++;
			}
			else
			{
				cnt[cntIdx]++;
			}
			// Judge from right
			if(n[j] != n[j+1])
			{
				nowR = j;
			}

			lBorder[i] = nowL;
			rBorder[j] = nowR;
		}

		// Query
		int l, r;
		for(int i = 0; i < query && scanf("%d %d", &l, &r) != EOF; i++)
		{
			l--, r--; // to 0-index

			// If it is in same group
			if(lBorder[l] == lBorder[r])
			{
				printf("%d\n", r - l + 1);
			}
			else
			{
				int maxFreq = INT_MIN;

				maxFreq = max(rBorder[l] - l + 1, maxFreq);

				maxFreq = max(r - lBorder[r] + 1, maxFreq);
				// mid
				for(int a = idxToGrp[l]+1; a <= idxToGrp[r]-1; a++)
				{
					maxFreq = max(cnt[a], maxFreq);
				}
				printf("%d\n", maxFreq);
			}
		}

		#if 0
		putchar('\n');
		for(int i = 0; i < len; i++)
			printf("%d ", idxToGrp[i]);
		putchar('\n');
		for(int i = 0; i < grp; i++)
			printf("%d ", cnt[i]);
		putchar('\n');
		for(int i = 0; i < len; i++)
			printf("%d ", lBorder[i]);
		putchar('\n');
		for(int i = 0; i < len; i++)
			printf("%d ", rBorder[i]);
		#endif
	}

	return 0;
}
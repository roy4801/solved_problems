/*
 * Uva 12015 - Google is Feeling Lucky
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct siteRank
{
	char url[100];
	int val;

	friend bool operator<(const siteRank &lhs, const siteRank &rhs);
};


bool operator<(const siteRank &lhs, const siteRank &rhs)
{
	return lhs.val > rhs.val;
}

// bool siteRankCompare(const siteRank &rhs, const siteRank &lhs)
// {
// 	return (rhs.val > lhs.val);
// }

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12015.in", "r", stdin);
	freopen("./testdata/12015.out", "w", stdout);
	#endif
	int cases, i = 1;

	scanf("%d", &cases);

	while(cases--)
	{
		printf("Case #%d:\n", i++);
		siteRank site[10];

		for(int i = 0; i < 10; i++)
			scanf("%s %d", site[i].url, &site[i].val);

		sort(site, site + 10);

		int max = site[0].val;
		for(int i = 0; i < 10; i++)
		{
			if(site[i].val != max)
			{
				break;
			}
			else
			{
				printf("%s\n", site[i].url);
			}
		}
	}

	return 0;
}
/*
 * Uva 11368 - Nested Dolls
 * author: roy4801
 * AC(C++) 0.290
 */
#include <iostream>
#include <algorithm>

using namespace std;

// O(n^2) 解QQ
//
// O(nlog n) -> https://sayaurobuchi.github.io/cmusu/2018/02/17/UVa_11368.html
//

struct Doll
{
	int w, h;
	int group;

	Doll()
	{
		w = h = 0;
		group = 0;
	}

	Doll(const Doll& other)
	{
		w = other.w;
		h = other.h;
		group = other.group;
	}

	Doll& operator=(const Doll &rhs)
	{
		w = rhs.w;
		h = rhs.h;
		group = rhs.group;
		return *this;
	}
	static struct Compare
	{
		bool operator()(const Doll &lhs, const Doll &rhs)
		{
			return (lhs.w > rhs.w ?
						true :
						lhs.w == rhs.w ?
							lhs.h < rhs.h
							: false);
		}
	}cmp;
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11368.in", "r", stdin);
	freopen("./testdata/11368.out", "w", stdout);
	#endif
	int cases, d, tmpW, tmpH;

	scanf("%d", &cases);

	while(cases-- && scanf("%d", &d) != EOF)
	{
		Doll *doll = new Doll[d];

		for(int i = 0; i < d && scanf("%d %d", &tmpW, &tmpH) != EOF; i++)
		{
			doll[i].w = tmpW;
			doll[i].h = tmpH;
		}

		// Sorting in the descending width
		// if the width is the same, sorting in the ascending height
		std::sort(doll, doll + d, Doll::cmp);

		int gIdx = 1; // group number
		for(int i = 0; i < d; i++)
		{
			int target = i + 1, now = i;

			// the most big one
			if(!doll[now].group)
			{
				doll[now].group = gIdx++;

				// Continuing to search a doll[target] that is smaller than doll[now] in size
				while(target < d)
				{
					if(!doll[target].group && doll[now].w > doll[target].w && doll[now].h > doll[target].h)
					{
						doll[target].group = doll[now].group;

						now = target;
					}

					target++;
				}
			}
		}

		for(int i = 0; i < d; i++)
		{
			printf("%d %d %d\n", doll[i].w, doll[i].h, doll[i].group);
		}
		// Count the group number
		int n = 1;

		for(int i = 0; i < d; i++)
			if(doll[i].group > n)
				n = doll[i].group;

		printf("%d\n", n);
		//
		delete [] doll;
	}

	return 0;
}
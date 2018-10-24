/*
 * UVA 1149 - Bin Packing
 * author: roy4801
 * AC(C++) 1.700
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1149"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 100005

int itemN, bL;
int item[N];
bool used[N];
int tmp;

int main()
{
	#ifdef DBG
	freopen(PROB TESTC ".in", "r", stdin);
	freopen(PROB ".out", "w", stdout);
	#endif
	int cases;

	cin >> cases;

	while(cases--)
	{
		cin >> itemN >> bL;

		int now = 0;

		// init & input
		memset(used, false, sizeof(used));
		for(int i = 0; i < itemN && cin >> item[i]; i++);

		sort(item, item + itemN);

		for(int i = itemN-1; i >= 0; i--)
		{
			// cout << item[i] << '\n';
			if(used[i])
			{
				continue;
			}

			if(item[i] == bL)
			{
				used[i] = true;
				now++;
			}
			else if(item[i] < bL)
			{
				// cout << "in" << '\n';
				int rem = bL - item[i];

				// cout << "rem:" << rem << '\n';

				used[i] = true;
				for(int j = 0; j < i; j++)
				{
					if(!used[j] && item[j] <= rem)
					{
						used[j] = true;
						// cout << "j:" << j << " item[j]:" << item[j] << '\n';
						break;
					}
				}

				now++;
			}
		}

		cout << now << '\n';

		if(cases)
			cout << '\n';
	}

	return 0;
}
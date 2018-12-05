/*
 * UVA 1619 - Feel Good
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1619"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
#define N 100000

LL val[N+5], pre[N+5];
int L[N+5], R[N+5];
int n;

void buildPre()
{
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + val[i];
}

int inteval(int i, int j)
{
	return pre[j] - pre[i-1];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	bool pt = false;
	while(cin >> n)
	{
		if(pt)
			putchar('\n');
		memset(val, 0, sizeof(val));
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		memset(pre, 0, sizeof(pre));

		for(int i = 1; i <= n && cin >> val[i]; i++);
		buildPre();
		// for(int i = 1; i <= n; i++)
		// 	cout << val[i] << ' ';
		// cout << '\n';

		// left
		for(int i = n; i >= 1; i--)
		{
			int j = i;
			while(j >= 1)
			{
				if(val[i] > val[j])
				{
					L[i] = j+1;
					break;
				}
				j--;
			}

			if(!L[i])
				L[i] = j+1;
		}

		// right
		for(int i = 1; i <= n; i++)
		{
			int j = i;
			while(j <= n)
			{
				if(val[i] > val[j])
				{
					R[i] = j-1;
					break;
				}
				j++;
			}

			if(!R[i])
				R[i] = j-1;
		}

		int maxI, maxV = INT_MIN;
		for(int i = 1; i <= n; i++)
		{
			int tmp = inteval(L[i], R[i]) * val[i];
			if(maxV < tmp)
			{
				maxV = tmp;
				maxI = i;
			}
		}

		cout << maxV << '\n' << L[maxI] << ' ' << R[maxI] << '\n';
		pt = true;
		// for(int i = 1; i <= n; i++)
		// 	cout << L[i] << ' ';
		// cout << '\n';
		// for(int i = 1; i <= n; i++)
		// 	cout << R[i] << ' ';
	}

	return 0;
}
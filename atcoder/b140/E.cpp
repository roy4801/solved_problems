/*
 *  E - Second Sum
 * author: roy4801
 * TLE(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "E"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 100000
int n, tmp;
int ans;
int arr[N+5];
int ma, mb; // 1st, 2nd
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n)
	{
		ans = 0;
		ma = mb = 0;
		
		for(int i = 0; i < n && cin >> arr[i]; i++);

		for(int i = 0; i < n; i++)
		{
			for(int j = i; j < n; j++)
			{
				if(j == i)
					ma = arr[i];
				else
				{
					if(j == i+1)
						mb = arr[j];
					
					if(arr[j] > ma)
					{
						mb = ma;
						ma = arr[j];
					}
					else if(arr[j] <= ma && arr[j] > mb)
						mb = arr[j];
					
					ans += mb;
				}
				// printf("%d ", mb);
			}
			// puts("");
		}
		cout << ans << '\n';
	}

	return 0;
}
/*
 * UVA 12100 - Printer Queue
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "12100"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int n, m; // jobs in que, pos of ur job
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int cases, tmp;
	cin >> cases;
	while(cases-- && cin >> n >> m)
	{
		deque<P> dq; // lev, idx
		int cat[10] = {0}; // num of each lev
		// input
		for(int i = 0; i < n && cin >> tmp; i++)
		{
			dq.emplace_back(tmp, i);
			cat[tmp]++;
		}

		int cnt = 0;
		int lev, idx; // lev, idx of dq.front()
		while(true)
		{
			tie(lev, idx) = dq.front();

			int canPop = 1; // flag(for &=)
			for(int i = lev+1; i < 10; i++) // check if lev greater than dq.front
				canPop &= (cat[i] == 0);
			// no one greater than dq.front()
			if(canPop)
			{
				cnt++;
				cat[lev]--;
				if(idx == m) // end
					break;
				dq.pop_front();
			}
			else // cycle
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}

		cout << cnt << '\n';
	}
	
	return 0;
}

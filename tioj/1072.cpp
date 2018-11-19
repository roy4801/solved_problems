/*
 * TIOJ 1072 - A.誰先晚餐
 * author: roy4801
 * AC(C++) 0.064
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1072"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<int, int> P;
#define F first
#define S second

#define N 10000
int n;

P di[N]; // cook, eat

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif

	while(cin >> n && n)
	{
		int totalC = 0, totalE = 0, t, more = INT_MIN;
		for(int i = 0; i < n && cin >> di[i].F >> di[i].S; i++);
		sort(di, di + n, [&](const P &lhs, const P &rhs)
			{
				return lhs.S > rhs.S;
			});

		// for(int i = 0; i < n; i++)
		// {
		// 	cout << di[i].F << ' ' << di[i].S << '\n';
		// }
		for(int i = 0; i < n; i++)
		{
			totalC += di[i].F;
			totalE += di[i].S;
		}
		t = totalC;

		for(int i = 0; i < n; i++)
		{
			totalC -= di[i].F;
			more = max(more, di[i].S - totalC);
		}

		cout << t + more << '\n';
		// puts("-----------------------");
	}
	

	return 0;
}
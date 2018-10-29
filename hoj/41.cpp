/*
 * HOJ 41 - 烤箱
 * author: roy4801
 * AC(C++)
 */
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define PROB "41"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 10000

int bag[N+5][2];

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int total, n;
	int weight, value;

	cin >> total >> n;

	for(int i = 0; i < n && cin >> value >> weight; i++)
	{
		// 窮舉總重
		for(int t = 0; t <= total; t++)
		{
			// 當剩餘重量（現在總承受 - 選的物品的重量）>= 0
			if(t - weight >= 0)
				bag[t][1] = max(bag[t - weight][1] + value, bag[t][0]);
		}

		for(int t = 0; t <= total; t++)
			bag[t][0] = bag[t][1];
	}

	cout << bag[total][1] << '\n';
	

	return 0;
}

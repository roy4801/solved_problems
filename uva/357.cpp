/*
 * UVA 357 - Let Me Count The Ways
 * author: roy4801
 * AC(C++) 0.000
 */
// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define PROB "357"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 30000
#define TYPE 5
typedef long long int LL;

LL dollar[N+5] = {1};
int val[] = {1, 5, 10, 25, 50};

void build()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j <= N; j++)
			if(j >= val[i])
				dollar[j] += dollar[j - val[i]];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	build();

	int n;

	while(~scanf("%d", &n))
	{
		if(dollar[n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", dollar[n], n);
	}

	return 0;
}

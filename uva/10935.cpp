/*
 * UVA 10935 - Throwing cards away I
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>
// #seq
using namespace std;

#define PROB "10935"
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

#define N 50
int num[2*N+5];
int n, siz;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int fr, ba; // front, back
	while(cin >> n && n)
	{
		for(int i = 1; i <= N; i++) num[i] = i;
		fr = 1, siz = ba = n;

		printf("Discarded cards:");
		while(siz > 1)
		{
			siz--;
			num[++ba] = num[fr+1];
			printf(" %d%s", num[fr], siz==1 ? "" : ",");
			fr += 2;
		}
		putchar('\n');
		printf("Remaining card: %d\n", num[ba]);
	}

	return 0;
}

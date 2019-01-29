/*
 * UVA 402 - M*A*S*H
 * author: roy4801
 * AC(C++) 0.090
 */
#include <bits/stdc++.h>
// #list
using namespace std;

#define PROB "402"
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
bool line[N+5]; // 1-index
int n, lp; // num of people, lucky point
int rem;   // remain num of people
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int card, cases = 1;
	while(cin >> n >> lp)
	{
		for(int i = 1; i <= n; i++)
			line[i] = true;

		rem = n;
		for(int i = 0; i < 20 && cin >> card; i++)
		{
			int cnt = 0;
			
			if(rem <= lp) continue;
			for(int j = 1; j <= n; j++)
			{
				if(line[j])
				{
					cnt++;
					if(cnt == card)
					{
						line[j] = false;
						rem--;
						cnt = 0;
					}
				}

				if(rem <= lp)
					break;
			}
		}

		printf("Selection #%d\n", cases++);
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(line[i])
			{
				cnt++;
				printf("%d%c", i, (cnt==rem ? '\n' : ' '));
			}
		putchar('\n');
	}

	return 0;
}

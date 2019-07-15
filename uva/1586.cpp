/*
 * UVA 1586 - Molar mass
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "1586"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
int kase;
char c, nowc;
double total, now;
int cnt;
bool dig;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	scanf("%d", &kase); getchar();
	while(kase--)
	{
		total = 0.0;
		cnt = 0;
		dig = false;

		while((c = getchar()))
		{
			if(isalpha(c) || c == '\n' || c == EOF)
			{
				if(cnt > 0)
				{
					// printf(">> %c %d\n", nowc, cnt);
					total += now * cnt;
					cnt = 0;
					dig = false;
				}
				
				cnt++;

				if(c == 'C') now = 12.01;
				else if(c == 'H') now = 1.008;
				else if(c == 'O') now = 16.00;
				else if(c == 'N') now = 14.01;
				// nowc = c;
			}
			else if(isdigit(c))
			{
				if(dig) // > 1 digit
				{
					cnt *= 10;
					cnt += c - '0';
				}
				else if(cnt == 1) // after the alpha
				{
					cnt *= c - '0';
					dig = true;
				}
			}
			if(c == '\n' || c == EOF) break;
		}

		printf("%.3lf\n", total);
	}
	return 0;
}
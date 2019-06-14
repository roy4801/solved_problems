/*
 * UVA 526 - String Distance and Transform Process
 * author: roy4801
 * AC(C++) 0.010
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "526"
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
#define N 80
int dp[N+5][N+5];
string fr, to;
int lup, ldown;
bool flag = false;
int ka = 1;
void print(int i, int j)
{
	if(i == 0 || j == 0)
	{
		while(i > 0)
		{
			printf("%d Delete %d\n", ka++, i);
			i--;
		}
		while(j > 0)
		{
			printf("%d Insert %d,%c\n", ka++, i+1, to[j-1]);
			j--;
		}
		return;
	}
	if(fr[i-1] == to[j-1])
		print(i-1, j-1);
	else
	{
		if(dp[i][j] == dp[i-1][j-1]+1) // replace
		{
			printf("%d Replace %d,%c\n", ka++, i, to[j-1]);
			print(i-1, j-1);
		}
		else if(dp[i][j] == dp[i-1][j]+1) // delete
		{
			printf("%d Delete %d\n", ka++, i);
			print(i-1, j);
		}
		else if(dp[i][j] == dp[i][j-1]+1) // insert
		{
			printf("%d Insert %d,%c\n", ka++, i+1, to[j-1]);
			print(i, j-1);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(getline(cin, fr) && getline(cin, to))
	{
		ka = 1;
		lup = fr.length(), ldown = to.length();
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= lup; i++)
			dp[i][0] = i;
		for(int j = 1; j <= ldown; j++)
			dp[0][j] = j;

		for(int i = 1; i <= lup; i++)
		{
			for(int j = 1; j <= ldown; j++)
			{
				if(fr[i-1] == to[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
			}
		}

		if(flag) puts("");
		printf("%d\n", dp[lup][ldown]);
		print(lup, ldown);
		flag = true;
	}
	return 0;
}

/*
 * Uva 11470 - Square Sums
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "11470"
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
#define N 10
int arr[N+5][N+5];
int n, T=1;
int main()
{
	while(cin >> n && n)
	{
		printf("Case %d:", T++);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> arr[i][j];

		int lev = ceil(n / 2.0);

		for(int i = 0; i < lev; i++)
		{
			int sum = 0;
			int k = n-i-1;
			for(int j = i; j < n-i; j++)
			{
				sum += arr[i][j]; // top row
				sum += arr[k][j]; // bottom row
				sum += arr[j][i]; // left col
				sum += arr[j][k]; // right col
				// printf("> i=%d j=%d k=%d\n", i, j, k);
			}
			sum -= arr[i][i];
			sum -= arr[k][i];
			sum -= arr[i][k];
			sum -= arr[k][k];

			if(n % 2 != 0 && i == lev-1)
				sum += arr[i][i];

			printf(" %d", sum);
		}
		puts("");
	}
}
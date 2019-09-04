/*
 * HOJ 456 - 帕斯卡三角形
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "456"
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
#define N 13
int arr[N+5][N+5];
int n, a, b;
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	arr[0][1] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= i; j++)
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];

	// for(int i = 1; i <= N; i++)
	// {
	// 	for(int j = 1; j <= i; j++)
	// 		printf("%d ", arr[i][j]);
	// 	puts("");
	// }
	while(cin >> n)
	{
		for(int i = 0; i < n && cin >> a >> b; i++)
			printf("%d\n", arr[a][b]);
	}

	return 0;
}

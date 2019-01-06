/*
 * UVA 11582 - Colossal Fibonacci Numbers!
 * author: roy4801
 * AC(C++) 0.040
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11582"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;

int mi(ULL a, ULL b, ULL n)
{
	if(b == 0) return 1;
	int h = mi(a, b/2, n) % n;
	h = (h * h) % n;
	if(b % 2 != 0) h = (h * (a%n)) % n;
	return h;
}
#define N 1000
vector<int> fibo[N+5];
ULL a, b, n;

void build()
{
	fibo[0].push_back(0), fibo[1].push_back(0);
	for(int n = 2; n <= N; n++)
	{
		fibo[n].push_back(1), fibo[n].push_back(1);
		for(int j = 2; j <= 10000; j++)
		{
			fibo[n].push_back((fibo[n][j-1]+fibo[n][j-2]) % n);
			if(fibo[n][j] == 1 && fibo[n][j-1] == 0)
			{
				fibo[n].pop_back();
				break;
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	build();
	int cases;
	cin >> cases;
	while(cases-- && cin >> a >> b >> n)
	{
		int p = fibo[n].size(), idx = mi(a%p, b, p);
		// cout << a%p << ' ' << b << ' ' << p << '\n';
		cout << (idx ? fibo[n][idx-1] : 0) << '\n';
	}
	// for(auto &i : fibo)
	// {
	// 	for(auto j : i)
	// 		cout << j << ' ';
	// 	puts("");
	// }
	return 0;
}
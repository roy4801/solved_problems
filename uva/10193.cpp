/*
 * Uva 10193 - All You Need Is Love
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "10193"
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
#define N 30
int kase;
string s1, s2;
int main()
{
	int T=1;
	cin >> kase;
	while(kase-- && cin >> s1 >> s2)
	{
		printf("Pair #%d: ", T++);
		int a = bitset<N+5>(s1).to_ulong();
		int b = bitset<N+5>(s2).to_ulong();
		int g = __gcd(a, b);
		// printf("%d\n", g);
		if(g != 1)
			puts("All you need is love!");
		else
			puts("Love is not all you need!");
	}
}
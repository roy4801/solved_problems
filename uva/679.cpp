/*
 * Uva 679 - Dropping Balls
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>
using namespace std;

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
int n, d, i;
int main()
{
	while(cin >> n && n != -1)
	{
		for(int a = 0; a < n && cin >> d >> i; a++)
		{
			int ni = 1;
			for(int j = 0; j < d-1; j++)
			{
				if(i % 2 != 0) // left(odd)
				{
					ni = ni * 2;
					i = (i+1) / 2;
				}
				else // right(even)
				{
					ni = ni * 2 + 1;
					i = i / 2;
				}
			}
			printf("%d\n", ni);
		}
	}
}
/*
 *  A - Shampoo
 * author: roy4801
 * AC(C++) 0.001
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "A"
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
int v, a, b, c;
int main()
{
	while(cin >> v >> a >> b >> c)
    {
        while(true)
        {
            if(v >= a)
                v -= a;
            else
            {
                puts("F");
                break;
            }
            if(v >= b)
                v -= b;
            else
            {
                puts("M");
                break;
            }
            if(v >= c)
                v -= c;
            else
            {
                puts("T");
                break;
            }
        }
    }
}
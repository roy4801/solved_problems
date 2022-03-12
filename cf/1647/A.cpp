/*
 * CF 1647 A Madoka and Math Dad
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "{pid}"
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

LL ans = INT_MIN;

void solve(int n /*target digit*/, LL cv /*current value*/, int cd /*current digit*/, LL r /*remain*/)
{
    if(r == 0)
    {
        // printf("%d ", cv);
        ans = max(ans, cv);
    }

    for(int i = r; i >= 1; i--)
    {
        if(r-i >= 0 && cd + 1 <= n && i != cv % 10)
        {
            cv = cv * 10 + i;
            solve(n, cv, cd+1, r-i);
            cv = (cv - i) / 10;
        }
    }
}

int main()
{
	int kase, n;
    cin >> kase;
    while(kase-- && cin >> n)
    {
        ans = INT_MIN;
        solve(n, 0, 0, n);
        // puts("");
        printf("%2d => %lld\n", n, ans);
        // puts("====================");
    }
}
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

string ans;

void solve(string s, int sum, int n)
{
    if(sum == n)
    {
        ans = max(ans, s);
        // cout << s << '\n';
    }

    for(int i = 1; i <= 2; i++)
    {
        if(s.back() == '0'+i)
            continue;

        if(sum + i <= n)
        {
            s.push_back('0'+i);
            solve(s, sum + i, n);
            s.pop_back();
        }
    }
}

int main()
{
	int kase, n;
    cin >> kase;
    while(kase-- && cin >> n)
    {
        ans = "";
        solve("", 0, n);
        // puts("---------------------");
        cout << ans << '\n';
        // puts("====================");
    }
}
/*
 * CSES 1069. Repetitions
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "Repetitions"
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

void __attribute__ ((constructor)) ctor() { USE_CPPIO(); }

int main()
{
    int ans = INT_MIN;
    string s;
    cin >> s;
    int n = s.size();
    int a = 0;
    for(int i = 1; i < n; i++)
    {
        if(s[i] != s[i-1])
        {
            ans = max(ans, i-a);
            a = i;
        }
   }
    ans = max(ans, n-a);
    cout << ans << '\n';
}

/*
 * CSES 1094 - Increasing Array
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "1094"
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
#define N 200000

void __attribute__ ((constructor)) ctor() { USE_CPPIO(); }

LL ans = 0;
int n;
int v[N+5];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n-1; i++)
    {
        if(v[i] > v[i+1])
        {
            ans += v[i]-v[i+1];
            v[i+1] = v[i];
        }
    }
    cout << ans << '\n';
}

/*
 * CSES 1068. Missing Number
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "Missing Number"
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

#define N 200000
bool vis[N+5];
int main()
{
    int n, m;
    cin >> n;
    for(int i = 0; i < n-1 && cin >> m; i++)
        vis[m] = true;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            cout << i << '\n';
}
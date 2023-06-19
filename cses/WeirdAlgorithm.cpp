/*
 * CSES Introductory Problems - WeirdAlgorithm
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "WeirdAlgorithm"
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

LL n;
int main()
{
    cin >> n;
    printf("%lld", n);
    while(n != 1)
    {
        if(n % 2 != 0)
            n = n*3 + 1;
        else
            n /= 2;
        printf(" %lld", n);
    }
}

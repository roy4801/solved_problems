/*
 * CSES 1070 - Permutations
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "1070"
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

#define N 1000000
int n;
int main()
{
    cin >> n;
    if(2 <= n && n <= 3)
        cout << "NO SOLUTION" << '\n';
    else
    {
        for(int i = 1; i <= n; i++)
            if((i & 1) == 0)
                printf("%d ", i);
        for(int i = 1; i <= n; i++)
            if((i & 1) != 0)
                printf("%d ", i); 
    }
}


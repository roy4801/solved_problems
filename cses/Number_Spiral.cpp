/*
 * CSES 1071 - Number Spiral
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "1071"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

int t;
LL x, y;
int main()
{
    cin >> t;
    for(int i = 0; i < t && cin >> y >> x; i++)
    {
        if(y < x)
        {
            if(x % 2 != 0)
                cout << x*x - y + 1 << '\n';
            else
                cout << (x-1)*(x-1) + y << '\n';
        }
        else if(y > x)
        {
            if(y % 2 != 0)
                cout << (y-1)*(y-1) + x << '\n';
            else
                cout << y*y - x + 1 << '\n';
        }
        else
        {
            cout << x*x - y + 1 << '\n';
        }
    }
}

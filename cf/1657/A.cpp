/*
 * CF 1657 A 
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front

vector<P> V;
int limit = 100;
void build()
{
    int a, b, c = 0; 
    int m = 2;
 
    while (c < limit)
    {
        for (int n = 1; n < m; ++n)
        {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;
 
            if(a <= 50 && b <= 50)
            {
                V.emplace_back(a, b);
                V.emplace_back(b, a);
            }
        }
        m++;
    }
}

int solve(int x, int y)
{
    int n = V.size();
    LL limit = (1LL << n) - 1LL;
    printf("FFF %d %lld\n", n, limit);
    
    for(int i = 0; i <= limit; i++)
    {
        int a = 0, b = 0, cnt = 0;
        // vector<P> dd;
        for(int j = 0; j < n; j++)
        {
            if((i >> j) & 1)
            {
                a += V[j].X;
                b += V[j].Y;
                // dd.emplace_back(V[j].X, V[j].Y);
                cnt++;
            }
        }
        // printf(">> %d %d\n", a, b);
        if(a == x && b == y)
        {
            puts("FUCK");
            return cnt;
        }
    }
    return 0;
}

/*
3
8 6
0 0
9 15
*/

int kase, x, y;
int main()
{
    build();
    sort(V.begin(), V.end());


    // for(auto i : V)
    //     printf("%d %d\n", i.X, i.Y);
    
	cin >> kase;
    while(kase-- && cin >> x >> y)
    {
        cout << solve(x, y) << '\n';
    }
}
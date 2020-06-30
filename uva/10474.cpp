/*
 * Uva 10474 - Zones
 * author: roy4801
 * AC(C++) 0.170
 */
#include <bits/stdc++.h>
using namespace std;
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
int n, q;
vector<int> v;
int main()
{
    int T=1;
	while(cin >> n >> q && (n || q))
    {
        v.clear();
        //
        int tmp;
        for(int i = 0; i < n && cin >> tmp; i++)
            v.PB(tmp);
        sort(v.begin(), v.end());
        printf("CASE# %d:\n", T++);
        for(int i = 0; i < q && cin >> tmp; i++) // query
        {
            auto it = lower_bound(v.begin(), v.end(), tmp);
            if(it != v.end() && *it == tmp)
            {
                printf("%d found at %d\n", tmp, it-v.begin() + 1);
            }
            else
            {
                printf("%d not found\n", tmp);
            }
        }
    }
}
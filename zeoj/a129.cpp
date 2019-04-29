/*
 * ZEOJ a129 - 最小生成樹
 * author: roy4801
 * AC(C++) 0.8
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "a129"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

#define N 100000
#define M 200000
struct edge
{
    int fr, to, wei;
    friend bool operator<(const edge &lhs, const edge &rhs)
    {
        return lhs.wei < rhs.wei;
    }
};

edge e[M+5];
int n, m;

// disjoint set
int p[N+5];

void init()
{
    for(int i = 0; i <= N; i++)
        p[i] = i;
}
int find(int x)
{
    return p[x] == x ? (p[x]) : (p[x] = find(p[x]));
}
void uni(int a, int b)
{
    p[find(a)] = find(b);
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
    USE_CPPIO();
    int fr, to, wei;
    while(cin >> n >> m)
    {
        init();
        for(int i = 0; i < m && cin >> fr >> to >> wei; i++)
        {
            e[i] = {fr, to, wei};
        }
        
        sort(e, e+m);
        
        LL sum = 0;
        int j = 0;
        for(int i = 0; i < m;)
        {
            fr = e[i].fr, to = e[i].to, wei = e[i].wei;
            if(find(fr) != find(to))
            {
                uni(fr, to);
                sum += wei;
                j++;
            }
            
            i++;
        }
        
        if(j == n-1)
            cout << sum << '\n';
        else
            cout << "-1" << '\n';
    }

	return 0;
}

/*
 * C - Collision 2
 * author: roy4801
 * (C++) 0.001
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

#define N 200000
int n, x, y;
vector<P> p;
string s;
//
set<int> Y;
int main()
{
	while(cin >> n)
    {
        map<int, vector<int>> M; // (y) => {pair number, ...}      
        p.clear();
        Y.clear();
        //
        for(int i = 0; i < n && cin >> x >> y; i++)
            p.PB(MP(x, y));
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            if(!Y.count(p[i].Y))
                Y.insert(p[i].Y);
            M[p[i].Y].PB(i);
        }
        //

        int ans = 0;
        for(int i : Y)
        {
            sort(M[i].begin(), M[i].end(), [&](int &lhs, int &rhs) {
                return p[lhs].X < p[rhs].X;
            });

            int state = 0;
            for(int j : M[i])
            {
                // printf("(%d %d, dir=%c), ", p[j].X, p[j].Y, s[j]);
                
                switch(state)
                {
                    case 0: // find R
                    {
                        if(s[j] == 'R')
                        {
                            state = 1;
                        }
                    }
                    break;
                    case 1: // find L
                    {
                        if(s[j] == 'L')
                        {
                            ans = 1;
                            goto end;
                        }
                    }
                    break;
                }
            }        
                
            // printf("ans = %d\n", ans);
            // puts("");
        }
        end:

        printf("%s\n", ans ? "YES" : "NO");
    }
}
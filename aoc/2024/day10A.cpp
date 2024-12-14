#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;
using LL = long long;
using P = pair<LL, LL>;
#define X first
#define Y second
#define MP make_pair

P dir[] = {
    {-1, 0}, // up
    { 0, 1}, // right
    { 1, 0}, // down
    { 0,-1}, // left
};
vector<string> in;
int n, m;

void input()
{
    string s;
    while(cin >> s)
        in.emplace_back(s);
    n = in.size();
    m = in[0].size();
}

inline bool ok(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

set<P> vis;
LL score = 0;
void dfs(int i, int j, int num)
{
    if(in[i][j] == '9')
    {
        score++;
        return;
    }
    
    for(auto [x, y] : dir)
    {
        auto p = MP(i+x, j+y);
        if(!vis.count(p) && ok(p.X, p.Y) && in[p.X][p.Y] == '0'+num)
        {
            vis.insert(p);
            dfs(p.X, p.Y, num+1);
        }
    }
}

void solve()
{
    vector<P> start;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(in[i][j] == '0')
                start.emplace_back(i, j);
    
    LL ans = 0;
    for(auto [i, j] : start)
    {
        vis.clear();
        score = 0;
        vis.emplace(i, j);
        dfs(i, j, 1);   
        
        ans += score;
    }
    
    cout << ans << '\n';
}

int main()
{
    freopen( "day12.in.6", "r", stdin );
    setvbuf( stdout, NULL, _IONBF, 0 );
    input();
    solve();
}

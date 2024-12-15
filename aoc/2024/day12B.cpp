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
ULL ans = 0;

void input()
{
    string tmp;
    while ( cin >> tmp )
        in.push_back( tmp );
    n = in.size();
    m = in[0].size();
}

void solve()
{
    vector<set<P>> groups;
    set<P> vis;

    auto is_valid = [&](P p)
    {
        auto [x, y] = p;
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    auto flood = [&]( int x, int y, set<P>& g )
    {
        queue<P> q;
        q.emplace( x, y );
        char c = in[x][y];
        g.emplace( x, y );
        vis.emplace( x, y );

        while ( !q.empty() )
        {
            auto [x, y] = q.front();
            q.pop();

            for ( auto [i, j] : dir )
            {
                auto p = MP( i + x, j + y );
                if ( is_valid( p ) && !vis.count( p ) && in[p.X][p.Y] == c )
                {
                    q.push( p );

                    g.emplace( p.X, p.Y );
                    vis.emplace( p.X, p.Y );
                }
            }
        }
    };

    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < n; j++ )
        {
            auto p = MP( i, j );
            if ( !vis.count( p ) )
            {
                //printf( "flood %d %d\n", i, j );
                groups.push_back( {} );
                flood( i, j, groups.back() );
            }
        }
    }

    for ( auto& g : groups )
    {
        vector<vector<bool>> v(n, vector<bool>(m));
        for(auto [i, j] : g)
            v[i][j] = 1;
        
        // extend out 
        vector<string> ex(n+2, string(m+2, '.'));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(v[i][j])
                    ex[1+i][1+j] = in[i][j];
                
        // for(int i = 0; i < n+2; i++)
        //     for(int j = 0; j < m+2; j++)
        //     printf("%c%s", ex[i][j], j==m+1 ? "\n" : "");
        
        int side = 0;

        // row
        for(int i = 1; i <= n+1; i++)
        {
            int line = 0;
            string prev, cur;
            for(int j = 1; j <= m+1; j++)
            {
                string tmp;
                tmp += ex[i][j];
                tmp += ex[i-1][j];
                cur = tmp;

                if(cur != prev && ex[i][j] != ex[i-1][j])
                {
                    line++;
                }
                prev = cur;
            }

            side += line;
        }
        
        // col
        for(int j = 1; j <= m+1; j++)
        {
            int line = 0;
            string prev, cur;
            for(int i = 1; i <= n+1; i++)
            {
                string tmp;
                tmp += ex[i][j];
                tmp += ex[i][j-1];
                cur = tmp;

                if(cur != prev && ex[i][j] != ex[i][j-1])
                {
                    line++;
                }
                prev = cur;
            }

            side += line;
        }
        
        ans += side * g.size();
    }

    cout << ans << '\n';
}

int main()
{
    freopen( "day12.in", "r", stdin );
    setvbuf( stdout, NULL, _IONBF, 0 );

    input();
    solve();
}

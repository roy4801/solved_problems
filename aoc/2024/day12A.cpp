#include <bits/stdc++.h>
using namespace std;
#include "aoc.h"

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
        LL p = 0;
        for ( auto [i, j] : g )
        {
            p += 4;

            int nei = 0;
            for ( auto [x, y] : dir )
            {
                if ( g.count( MP( i + x, j + y ) ) )
                {
                    nei++;
                }
            }

            p -= nei;
        }

        if ( p )
        {
             //printf("%d %d = %d\n", g.size(), p, p*g.size());
            ans += p * g.size();
        }
    }

    cout << ans << '\n';
}

int main()
{
    freopen( "C:/Users/roy4801/Downloads/day12.in", "r", stdin );
    setvbuf( stdout, NULL, _IONBF, 0 );

    input();
    solve();
}

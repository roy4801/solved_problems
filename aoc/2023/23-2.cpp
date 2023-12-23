/*
 * Acvent of Code Day 23: A Long Walk (part 2)
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "../helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define arr array
#define PB push_back
#define MP make_pair
#define X first
#define Y second

vector<string> M, M2;
set<P> vis;
int n, m;
P st, en; // start, end

P dir[4] = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1},  // right
};

bool ok(int i, int x, int y)
{
    return 0 <= x && x < n &&
           0 <= y && y < m &&
           M[x][y] != '#';
}
bool IsSlope(char c)
{
    return c == '^' || c == '>' || c == '<' || c == 'v';
}

bool IsJunction(int x, int y)
{
    int slope = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dir[i].X, ny = y+dir[i].Y;
        if(!ok(i, nx, ny))
            continue;
        if(IsSlope(M[nx][ny]))
            slope++;
    }
    return slope >= 3;
}
set<P> nodes;
map<P, int> idxToId;
int gid = 0;
int GetID(int x, int y)
{
    if(!idxToId.count({x, y}))
    {
        idxToId[{x, y}] = gid++;
    }
    return idxToId[{x, y}];
}
int GetID(P p) { return GetID(p.X, p.Y); }
vector<vector<P>> graph; // from -> {(to1, weight1), (to2, weight2), ...}
P orig;
void Build(int x, int y, int d)
{
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dir[i].X, ny = y+dir[i].Y;
        if(!ok(i, nx, ny))
            continue;

        if (!vis.count({nx, ny}))
        {
            vis.insert({nx, ny});
            if(nodes.count({nx, ny}))
            {
                graph[GetID(orig)].emplace_back(GetID(nx, ny), d+1);
            }
            else
            {
                Build(nx, ny, d+1);
            }
        }
    }
}

int ans = INT_MIN;
set<int> vis2;
void solve(int fr, int d)
{
    if(fr == GetID(en))
    {
        ans = max(ans, d);
        return;
    }

    for(auto [to, w] : graph[fr])
    {
        if(!vis2.count(to))
        {
            vis2.insert(to);
            solve(to, d+w);
            vis2.erase(to);
        }
    }
}

int main()
{
    freopen("23.in", "r", stdin);

    // input
    string in;
    while(getline(cin, in))
        M.emplace_back(in);
    n = M.size(), m = M[0].size();

    M2 = M; // debug

    // find start & end
    st.X = 0;
    en.X = n-1;
    for(int i = 0; i < m; i++)
        if(M[0][i] == '.')
            st.Y = i;
    for(int i = 0; i < m; i++)
        if(M[n-1][i] == '.')
            en.Y = i;

    // build graph
    nodes.emplace(st.X, st.Y);
    nodes.emplace(en.X, en.Y);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(IsJunction(i, j))
            {
                nodes.emplace(i, j);
            }
    // bfs eveny node to build the whole graph
    graph.resize(nodes.size());
    for(auto [x, y] : nodes)
    {
        orig = {x, y};
        vis.insert({x, y});
        Build(x, y, 0);
        vis.clear();
    }

    printf("start %d (%d, %d)\n", GetID(st), st.X, st.Y);
    printf("end %d (%d, %d)\n", GetID(en), en.X, en.Y);

    solve(GetID(st), 0);

    printf("answer = %d\n", ans);

#if 0
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            printf("%c%s", M2[i][j], j==m-1?"\n":"");
#endif
}

/*
start 0 (0, 1)
end 35 (140, 139)
answer = 6498

[Done] exited with code=0 in 35.589 seconds
*/

#include <bits/stdc++.h>
using namespace std;
bool __DEBUG__ = 1;
#define dbg(...) do { if(__DEBUG__) { printf(__VA_ARGS__); } } while(0)
#define X first
#define Y second
using P = pair<int,int>;
using ULL = unsigned long long;

P dir_offset[] = {
    {-1, 0}, // up
    { 0, 1}, // right
    { 1, 0}, // down
    { 0,-1}, // left
};
inline bool is_guard(char c) { return c == '^' || c == '>' || c == 'v' || c == '<'; }
inline bool is_wall(char c) { return c == '#'; }
inline int get_dir(char c) { return string("^>v<").find(c); }
P pos;         // guard cur pos
int dir;       // guard cur dir
P start_pos;   // guard start pos
int start_dir; // guard start dir
vector<string> M;
int n, m;
inline bool is_out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
int ans = 0;

bool simulate(vector<string> M, P guard, int dir, P block)
{
    M[block.X][block.Y] = '#';

    int step = 0;
    while(step < n*m)
    {
        auto [x, y] = guard;
        auto [offx, offy] = dir_offset[dir];
        int nx = x + offx, ny = y + offy;

        if(!is_out(nx, ny) && is_wall(M[nx][ny]))
        {
            dir++;
            dir %= 4;
        }
        else
        {
            if(is_out(nx, ny))
            {
                return 0;
            }
            guard = {nx, ny};
        }

        step++;
    }
    return 1;
}

void solve()
{
    set<P> vis;

    while(1)
    {
        auto [x, y] = pos;
        auto [offx, offy] = dir_offset[dir];
        int nx = x + offx, ny = y + offy;

        if(!is_out(nx, ny) && is_wall(M[nx][ny]))
        {
            dir++;
            dir %= 4;
        }
        else
        {
            if(is_out(nx, ny))
            {
                break;
            }

            if(simulate(M, start_pos, start_dir, {nx, ny}))
            {
                dbg(">> %d %d\n", nx, ny);
                vis.emplace(nx, ny);
            }

            pos = {nx, ny};
        }
    }

    ans = vis.size();
}

int main()
{
    freopen("day06.in", "r", stdin);
    setvbuf(stdout, NULL, _IONBF, 0);

    string s;
    while(cin >> s)
        M.emplace_back(s);

    n = M.size();
    m = M[0].size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(is_guard(M[i][j]))
            {
                start_pos = pos = {i, j};
                start_dir = dir = get_dir(M[i][j]);
                dbg("> %d %d %c %d\n", pos.X, pos.Y, M[i][j], dir);
            }

    solve();

    cout << ans << '\n';
}

/*
possible block position for example input
6 3
7 6
7 7
8 1
8 3
9 7
*/
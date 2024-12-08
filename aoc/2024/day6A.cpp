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
P pos; // guard
int dir; // 
vector<string> M;
int n, m;
inline bool is_out(int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; }
int ans = 0;

void solve()
{
    int step = 0;

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
            M[x][y] = 'X';
            if(is_out(nx, ny))
            {
                break;
            }
            pos = {nx, ny};
        }

        step++;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(M[i][j] == 'X')
                ans++;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dbg("%c%s", M[i][j], j==m-1?"\n":"");
}

int main()
{
    freopen("C:\\Users\\roy4801\\Desktop\\Program\\my_code\\solved_problems\\aoc\\2024\\day06.in", "r", stdin);
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
                pos = {i, j};
                dir = get_dir(M[i][j]);
                dbg("> %d %d %c %d\n", pos.X, pos.Y, M[i][j], dir);
            }

    solve();

    cout << ans << '\n';
} 
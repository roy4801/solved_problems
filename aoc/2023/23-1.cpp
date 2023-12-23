/*
 * Acvent of Code Day 23: A Long Walk
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "..\helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define arr array
#define PB push_back
#define MP make_pair
#define X first
#define Y second

vector<string> M;
vector<vector<int>> dis;
int n, m;
P st, en; // start, end

P dir[4] = {
    {-1, 0}, // up
    {1, 0},  // down
    {0, -1}, // left
    {0, 1},  // right
};
char stop[4] = {
    'v',
    '^',
    '>',
    '<',
};

bool ok(int i, int x, int y)
{
    return 0 <= x && x < n &&
           0 <= y && y < m &&
           M[x][y] != '#' &&
           M[x][y] != stop[i];
}

int ans = INT_MIN;
void solve(int px, int py, int x, int y, int d)
{
    dis[x][y] = d;

    if(x == en.X && y == en.Y)
    {
        printf("Complete in %d steps\n", d);
        ans = max(ans, d);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int nx = x+dir[i].X, ny = y+dir[i].Y;
        if(!ok(i, nx, ny) || (nx == px && ny == py))
            continue;
    
        if (d+1 > dis[nx][ny])
        {
            // printf("%d %d -> %d %d -> %d %d\n", px, py, x, y, nx, ny);
            solve(x, y, nx, ny, d+1);
        }
    }
}

int main()
{
    freopen("23.in", "r", stdin);

    string in;
    while(getline(cin, in))
        M.emplace_back(in);
    n = M.size(), m = M[0].size();
    dis.assign(n, vector<int>(m, -1));

    st.X = 0;
    en.X = n-1;
    for(int i = 0; i < m; i++)
        if(M[0][i] == '.')
            st.Y = i;
    for(int i = 0; i < m; i++)
        if(M[n-1][i] == '.')
            en.Y = i;

    DBG(en);

    solve(-1, -1, st.X, st.Y, 0);

    printf("answer = %d\n", ans);
}

// AC 9ms
#include <bits/stdc++.h>
using namespace std;
#define N 20
using P=pair<int, int>;
using T=tuple<int, int, int>;
#define MP make_pair
#define MT make_tuple
char m[N+5][N+5];
int H, W;
int dirs[][2] = {
    {0, -1}, // up
    {0, 1},  // down
    {-1, 0}, // left
    {1, 0}   // right
};
queue<T> q;
int mw[N+5][N+5];
int maxw;
void init()
{
    maxw = 0;
    while(!q.empty()) q.pop();
    memset(mw, -1, sizeof(mw));
}
bool ok(int i, int j)
{
    return i >= 1 && i <= H && j >= 1 && j <= W &&
        m[i][j] == '.' && mw[i][j] == -1;
}
void bfs(int i, int j, int w)
{
    if(!ok(i, j)) return;
    mw[i][j] = w;
    q.push(MT(i, j, w));
    while(!q.empty())
    {
        tie(i, j, w) = q.front(); q.pop();
        // printf(">> %d %d %d\n", i, j, w);
        for(int d = 0; d < 4; d++)
        {
            int ti = i+dirs[d][0], tj = j+dirs[d][1];
            if(ok(ti, tj))
            {
                mw[ti][tj] = w+1; // update
                q.push(MT(ti, tj, mw[ti][tj]));
            }
        }
    }
    // find max
    for(int a = 1; a <= H; a++)
        for(int b = 1; b <= W; b++)
            maxw = max(maxw, mw[a][b]);
}

int main(int argc, char *argv[])
{
    while(~scanf("%d %d", &H, &W))
    {
        // input
        getchar();
        for(int i = 1; i <= H; i++)
        {
            for(int j = 1; j <= W; j++)
            {
                m[i][j] = getchar();
            }
            getchar();
        }
        // solve
        int ans = 0;
        for(int i = 1; i <= H; i++)
            for(int j = 1; j <= W; j++)
            {
                init();
                bfs(i, j, 0);
                ans = max(ans, maxw);
            }
        printf("%d\n", ans);
    }
}
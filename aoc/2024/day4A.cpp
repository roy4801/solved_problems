#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> in;
int ans = 0;

bool eq(const string& s)
{
    return s == "XMAS";
}

int offset[][2] = {
    {-1, 0}, // up
    {-1, 1}, // up right
    { 0, 1}, // right
    { 1, 1}, // down right
    { 1, 0}, // down
    { 1,-1}, // down left
    { 0,-1}, // left
    {-1,-1}  // up left
};

void solve(int i, int j, int dir, int dep, string s)
{
    //printf("> %d %d %s\n", i, j, s.c_str());
    if(eq(s))
    {
        ans++;
        return;
    }
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
    if(s.size() >= 4)
        return;

    s += in[i][j];
    i += offset[dir][0];
    j += offset[dir][1];
    dep += 1;
    solve(i, j, dir, dep, s);
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    string s;
    while(cin >> s)
        in.push_back(s);

    n = in.size();
    m = in[0].size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 8; k++)
                solve(i, j, k, 0, "");

    cout << ans << '\n';
}

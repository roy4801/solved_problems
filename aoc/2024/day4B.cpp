#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> in;
int ans = 0;

bool match_pattern(int i, int j)
{
    string tmp;

    /*
    o..
    .o.
    ..o
    */
    for(int k = 0; k < 3; k++)
        tmp += in[i+k][j+k];
    if(tmp != "MAS" && tmp != "SAM")
        return 0;

    /*
    ..o
    .o.
    o..
    */
    tmp = "";
    for(int k = 0; k < 3; k++)
        tmp += in[i+2-k][j+k];
    if(tmp != "MAS" && tmp != "SAM")
        return 0;

    return 1;
}

void debug(int i, int j)
{
    string patt = "o.o"
                  ".o."
                  "o.o";
    for(int a = 0; a < 3; a++)
    {
        for(int b = 0; b < 3; b++)
        {
            if(patt[a*3+b] == 'o')
                cout << in[i+a][j+b];
            else
                cout << '.';
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i+2 >= n || j+2 >= m)
                continue;

            if(!match_pattern(i, j))
                continue;

            // debug(i, j);

            ans++;
        }
    }
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    string s;
    while(cin >> s)
        in.push_back(s);

    n = in.size();
    m = in[0].size();

    solve();

    cout << ans << '\n';
}

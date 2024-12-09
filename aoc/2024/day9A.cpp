#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;
using P = pair<int,int>;
#define X first
#define Y second

string in;
vector<ULL> s;
int n;

void input()
{
    cin >> in;
    n = in.size();
}

void solve()
{
    int id = 0;
    for(int i = 0; i < n; i++)
    {
        int num = in[i] - '0';
        if(i % 2 != 0)
        {
            for(int j = 0; j < num; j++)
                s.push_back(-1);
        }
        else
        {
            for(int j = 0; j < num; j++)
                s.push_back(id);
            id++;
        }
    }
    n = s.size();

    int i = 0, j = n-1;
    while(i < j)
    {
        if(s[i] != -1)
            i++;
        if(s[j] == -1)
            j--;
        if(s[i] == -1 && s[j] != -1)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    ULL ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == -1)
            break;
        // printf("> %d += %d * %d = %d\n", ans, i, (s[i]-'0'), (s[i]-'0') * i);
        ans += s[i] * i;
    }

    cout << ans << '\n';
}

int main()
{
    freopen("day9A.in", "r", stdin);
    setvbuf(stdout, NULL, _IONBF, 0);

    input();
    solve();
}

/*
Think1: the id could >= 10
Thinl2: The full id should be used when calc the checksum 
*/
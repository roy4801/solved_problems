#include <bits/stdc++.h>
using namespace std;

int ans = 0;
map<int, set<int>> R;

bool ok(int n, vector<int>& v)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(!R[v[i]].count(v[j]))
                return 0;
        }
    }
    return 1;
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    string s;
    while(getline(cin, s) && s != "")
    {
        int a, b;
        sscanf(s.c_str(), "%d|%d", &a, &b);
        // cout << a << ' '<< b << '\n';
        R[a].insert(b);
    }
    while(getline(cin, s) && s != "")
    {
        vector<int> v;
        stringstream ss(s);
        string tmp;
        while(getline(ss, tmp, ','))
        {
            v.push_back(stol(tmp));
        }

        if(ok(v.size(), v))
        {
            int num = v[v.size()/2];
            printf("> OK %d\n", num);
            ans += num;
        }
        else
        {
            printf("> NOT OK\n");
        }
    }

    cout << ans << '\n';
}
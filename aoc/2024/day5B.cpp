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

        if(!ok(v.size(), v))
        {
            vector<int> new_v(v.size());
            for(int i = 0; i < v.size(); i++)
            {
                int score = 0;
                for(int j = 0; j < v.size(); j++)
                {
                    if(i == j)
                        continue;

                    if(!R[v[i]].count(v[j]))
                    {
                        score++; 
                    }
                }

                new_v[score] = v[i];
            }

            ans += new_v[v.size()/2];
        }
    }

    cout << ans << '\n';
}
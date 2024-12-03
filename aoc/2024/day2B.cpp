#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tmp;
    string s;
    int ans = 0;
    vector<int> v;
    
    int DEBUG = 1;
    auto debug = [DEBUG](vector<int> &v) {
        if(DEBUG <= 0) return;
        printf(">> ");
        for(int i : v)
            printf("%d ", i);
        cout << '\n';
    };
    auto IsSafe = [debug](vector<int> &v)
    {
        bool safe = 1;
        if(v[0] < v[1])
        {
            for(int i = 0; i < v.size() - 1; i++)
                if(v[i] >= v[i+1] || abs(v[i] - v[i+1]) > 3)
                    safe = 0, debug(v);
        }
        else if(v[0] > v[1])
        {
            for(int i = 0; i < v.size() - 1; i++)
                if(v[i] <= v[i+1] || abs(v[i] - v[i+1]) > 3)
                    safe = 0, debug(v);
        }
        else
        {
            safe = 0, debug(v);
        }
        return safe;
    };
    while(getline(cin, s))
    {
        //cout << s << '\n';
        v.clear();
        stringstream ss(s);
        while(ss >> tmp)
            v.push_back(tmp);
        
        if(DEBUG)
        {
            printf("> ");
            for(int i : v)
                printf("%d ", i);
            puts("");
        }

        if(!IsSafe(v))
        {
            for(int i = 0; i < v.size(); i++)
            {
                auto vv = v;
                vv.erase(vv.begin()+i);
                if(IsSafe(vv))
                {
                    ans++;
                    break;
                }
            }
        }
        else
            ans++;
    }

    cout << ans << '\n';
}

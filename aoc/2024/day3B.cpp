#include <bits/stdc++.h>
using namespace std;

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    
    string s;
    char c;
    while(cin >> c)
        s += c;
    
    vector<pair<int,int>> v; // pos, mul value
    long long ans = 0;

    string ss = s;
    for(size_t i = ss.find("do()"); i != string::npos; i = ss.find("do()", i+4))
    {
        v.emplace_back(i, -1);
    }

    ss = s;
    for(size_t i = ss.find("don't()"); i != string::npos; i = ss.find("don't()", i+7))
    {
        v.emplace_back(i, -2);
    }

    size_t i = s.find("mul(");
    while(i != string::npos)
    {
        i += 4;

        int co = s.find(',', i);
        if(co == string::npos)
        {
            i = s.find("mul(", i);
            continue;
        }
        int rb = s.find(')', co);
        if(rb == string::npos)
        {
            i = s.find("mul(", i);
            continue;
        }

        bool a = all_of(s.begin()+i, s.begin()+co, [](char c){ return isdigit(c); });
        bool b = all_of(s.begin()+co+1, s.begin()+rb, [](char c){ return isdigit(c); });
        if(a && b)
        {
            string as = s.substr(i, co-i);
            string bs = s.substr(co+1, rb-co-1);
            int an = stol(as), bn = stol(bs);
            // cout << as << ' ' << bs << '\n';
            v.emplace_back(i-4, an * bn);
            i = s.find("mul(", rb+1);
        }
        else
        {
            i = s.find("mul(", i);
        }
    }

    sort(v.begin(), v.end());

    bool enable = 1;
    for(auto [pos, val] : v)
    {
        if(val < 0)
        {
            if(val == -1) enable = 1;
            if(val == -2) enable = 0;
        }
        else
        {
            if(enable)
                ans += val;
        }
    }

    cout << ans << '\n';
}

/*
xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
*/
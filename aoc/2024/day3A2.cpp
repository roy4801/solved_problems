#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    
    char c;
    while(cin >> c)
        s += c;
    
    int ans = 0;
    size_t i = s.find("mul(");
    while(i != string::npos)
    {
        i += 4;

        int co = s.find(',', i);
        if(co == string::npos)
            continue;
        int rb = s.find(')', co);
        if(rb == string::npos)
            continue;

        bool a = all_of(s.begin()+i, s.begin()+co, [](char c){ return isdigit(c); });
        bool b = all_of(s.begin()+co+1, s.begin()+rb, [](char c){ return isdigit(c); });
        if(a && b)
        {
            string as = s.substr(i, co-i);
            string bs = s.substr(co+1, rb-co-1);
            int an = stol(as), bn = stol(bs);
            // cout << as << ' ' << bs << '\n';
            ans += an * bn;
        }

        i = s.find("mul(", i);
    }

    cout << ans << '\n';
}

/*
xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
*/
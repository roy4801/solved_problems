#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;

vector<int> v;
ULL target;
ULL ans = 0;

ULL to_num (string x)
{
    ULL result = 0;
    for(auto& c : x)
    {
        result *= 10;
        result += c - '0';
    }
    return result;
}

void solve(int n)
{
    int up = pow(3, n-1);
    for(int i = 0; i < up; i++)
    {
        // 0=+, 1=*, 2=||
        
        ULL tmp = v[0];
        int state = i;
        for(int j = 0; j < n-1; j++)
        {
            if(state % 3 == 0)
            {
                tmp += v[j+1];
            }
            else if(state % 3 == 1)
            {
                tmp *= v[j+1];
            }
            else 
            {
                tmp = to_num(to_string(tmp) + to_string(v[j+1]));
            }
            state /= 3;
        }

        if(tmp == target)
        {
            ans += target;
            return;
        }
    }
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    string s;
    while(getline(cin, s))
    {
        cout << s << endl;
        stringstream ss(s);

        ss >> target;
        ss.get();

        v.clear();
        int tmp;
        while(ss >> tmp)
        {
            v.push_back(tmp);
        }

        int n = v.size();
        solve(n);
    }

    cout << ans << '\n';
} 
#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;

vector<int> v;
ULL target;
ULL ans = 0;

inline int digit (ULL v)
{
    int r = 0;
    r = (v >= 10000000000000000000ULL) ? 19 : (v >= 1000000000000000000ULL) ? 18 : 
        (v >= 100000000000000000ULL) ? 17 : (v >= 10000000000000000ULL) ? 16 :
        (v >= 1000000000000000ULL) ? 15 : (v >= 100000000000000ULL) ? 14 :
        (v >= 10000000000000ULL) ? 13 : (v >= 1000000000000ULL) ? 12 :
        (v >= 100000000000ULL) ? 11 : (v >= 10000000000ULL) ? 10 :
        (v >= 1000000000ULL) ? 9 : (v >= 100000000ULL) ? 8 : (v >= 10000000ULL) ? 7 : 
        (v >= 1000000ULL) ? 6 : (v >= 100000ULL) ? 5 : (v >= 10000ULL) ? 4 : 
        (v >= 1000ULL) ? 3 : (v >= 100ULL) ? 2 : (v >= 10ULL) ? 1 : 0;
    return r+1;
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
                int d = digit(v[j+1]);
                tmp *= pow(10, d);
                tmp += v[j+1];
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
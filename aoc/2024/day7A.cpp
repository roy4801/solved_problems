#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;

vector<int> v;
ULL target;
ULL ans = 0;

void solve(int n)
{

    int up = pow(2, n-1);
    for(int i = 0; i < up; i++)
    {
        bitset<32> vis(i); // 0=+, 1=*
        
        ULL tmp = v[0];
        for(int j = 0; j < n-1; j++)
        {
            if(vis[j] == 0)
            {
                tmp += v[j+1];
            }
            else
            {
                tmp *= v[j+1];
            }
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
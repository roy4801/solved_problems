#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tmp;
    string s;
    int ans = 0;
    vector<int> v;
    auto debug = [&](){
        printf(">> ");
        for(int i : v)
            printf("%d ", i);
        cout << '\n';
    };
    while(getline(cin, s))
    {
        cout << s << '\n';
        v.clear();
        stringstream ss(s);
        while(ss >> tmp)
            v.push_back(tmp);
        
        printf("> ");
        for(int i : v)
            printf("%d ", i);
        puts("");

        bool safe = 1;
        if(v[0] < v[1])
        {
            for(int i = 0; i < v.size() - 1; i++)
                if(v[i] >= v[i+1] || abs(v[i] - v[i+1]) > 3)
                    safe = 0, debug();
        }
        else if(v[0] > v[1])
        {
            for(int i = 0; i < v.size() - 1; i++)
                if(v[i] <= v[i+1] || abs(v[i] - v[i+1]) > 3)
                    safe = 0, debug();
        }
        else
            safe = 0, debug();

        if(safe)
            ans++;
    }

    cout << ans << '\n';
}

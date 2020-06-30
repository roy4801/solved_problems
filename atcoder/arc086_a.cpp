// AC 0.065
#include <bits/stdc++.h>
using namespace std;
#define N 200000
int n, k;
int cnt[N+5];
vector<pair<int, int>> v;
int in;
int main(int argc, char *argv[])
{
    while(cin >> n >> k && (n||k))
    {
        memset(cnt, 0, sizeof(cnt));
        v.clear();
        //
        for(int i = 0; i < n && cin >> in; i++)
            cnt[in]++;
        for(int i = 0; i <= N; i++)
            if(cnt[i])
                v.push_back(make_pair(cnt[i], i));
        sort(v.begin(), v.end());
        int d = v.size() - k, ans = 0;
        for(int i = 0; i < d; i++)
        {
            ans += v[i].first;
        }
        printf("%d\n", ans);
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    vector<int> A;
    map<int,int> M;
    while(cin >> a >> b)
    {
        A.push_back(a);
        M[b]++;
    }

    int n = A.size(), ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += A[i] * M[A[i]];
    }

    cout << ans << '\n';
}

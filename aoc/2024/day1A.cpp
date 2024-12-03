#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    vector<int> A, B;
    while(cin >> a >> b)
    {
        A.push_back(a);
        B.push_back(b);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size(), ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += abs(A[i] - B[i]);
    }

    cout << ans << '\n';
}

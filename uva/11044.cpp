/*
 * Uva 11044 - Searching for Nessy
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11044.in", "r", stdin);
    freopen("./testdata/11044.out", "w", stdout);
    #endif
    int cases, n, m;

    scanf("%d", &cases);

    while(cases-- && scanf("%d %d", &n, &m) != EOF)
    {
        printf("%d\n", (n / 3) * (m / 3));
    }

    return 0;
}
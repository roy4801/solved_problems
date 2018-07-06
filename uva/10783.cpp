/*
 * Uva 10783 - Odd Sum
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10783.in", "r", stdin);
    freopen("./testdata/10783.out", "w", stdout);
    #endif
    int cases, upper, lower;

    scanf("%d", &cases);

    for(int a = 0; a < cases && scanf("%d %d", &lower, &upper) != EOF; a++)
    {
        int sum = 0;

        int u = upper % 2 != 0 ? (upper - 1) / 2 : ((upper-1) - 1) / 2;
        int l = lower % 2 != 0 ? (lower - 1) / 2 : ((lower+1) - 1) / 2;

        sum += (u - l + 1) * (l + u) + (u - l + 1);

        printf("Case %d: %d\n", a+1, sum);
    }

    return 0;
}

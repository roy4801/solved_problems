/*
 * Uva 11727 - Cost Cutting
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11727.in", "r", stdin);
    freopen("./testdata/11727.out", "w", stdout);
    #endif
    int cases, salary[3];

    scanf("%d", &cases);

    for(int i = 1; i <= cases && scanf("%d %d %d", &salary[0], &salary[1], &salary[2]) != EOF; i++)
    {
        sort(salary, salary + 3);

        printf("Case %d: %d\n", i, salary[1]);
    }    

    return 0;
}
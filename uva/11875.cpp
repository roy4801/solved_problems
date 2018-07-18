/*
 * Uva 11875 - 
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11875.in", "r", stdin);
    freopen("./testdata/11875.out", "w", stdout);
    #endif
    int cases, num;

    scanf("%d", &cases);

    for(int i = 0; i < cases && scanf("%d", &num) != EOF; i++)
    {
        int year[num];

        for(int a = 0; a < num; a++)
            scanf("%d", &year[a]);

        sort(year, year + num);

        printf("Case %d: %d\n", i+1, year[(num-1) / 2]);
    }

    return 0;
}
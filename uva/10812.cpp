/*
 * Uva 10812 - Beat the Spread!
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10812.in", "r", stdin);
    freopen("./testdata/10812.out", "w", stdout);
    #endif
    int cases;
    int sum, diff;

    scanf("%d", &cases);
    while(cases-- && scanf("%d %d", &sum, &diff) != EOF)
    {
        if(sum < diff)
            printf("impossible\n");
        else
        {
            int a = (sum - diff) / 2;
            int b = sum - a;

            if(max(a, b) - min(a, b) == diff)
            {
                printf("%d %d\n", max(a, b), min(a, b));
            }
            else
                printf("impossible\n");
        }
    }

    return 0;
}
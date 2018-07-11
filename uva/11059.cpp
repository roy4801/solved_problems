/*
 * Uva 11059 - 
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11059.in", "r", stdin);
    freopen("./testdata/11059.out", "w", stdout);
    #endif
    int num;
    int times = 1;

    while(scanf("%d", &num) != EOF)
    {
        int n[num], minus = 0, product = 1;
        printf("Case #%d: The maximum product is ", times++);

        for(int i = 0; i < num; i++)
        {
            scanf("%d", &n[i]);
        }

        long long int max = LLONG_MIN;
        for(int i = 0; i < num; i++)
        {
            long long int product = 1;

            for(int j = i; j < num && n[j] != 0; j++)
            {
                product *= (long long int)n[j];

                if(max < product)
                {
                    max = product;
                }
            }
        }

        printf("%lld.\n\n", max >= 0 ? max : 0);

    }

    return 0;
}
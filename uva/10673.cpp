/*
 * Uva 10673 -
 * author: roy4801
 * AC(C++) 0.160
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10673.in", "r", stdin);
    freopen("./testdata/10673.out", "w", stdout);
    #endif
    int cases;
    int x, k;

    scanf("%d", &cases);

    while(cases-- && scanf("%d %d", &x, &k) != EOF)
    {
        int fl = (int)floor((double)x / (double)k), ce = (int)ceil((double)x / (double)k);

        int p = 0, q = 1;
        int limit = x / max(fl, ce) + 1;

        while(p <= limit)
        {
            if(p * fl + q * ce == (int)x)
            {
                printf("%d %d\n", p, q);
                break;
            }
            if(++q > limit)
            {
                q = 0;
                p++;
            }
        }
    }

    return 0;
}
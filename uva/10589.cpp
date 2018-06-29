/*
 * Uva 10589 - Area
 * author: roy4801
 * AC(C++) 0.060
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10589.in", "r", stdin);
    freopen("./testdata/10589.out", "w", stdout);
    #endif
    int n, a;

    while(scanf("%d %d", &n , &a) != EOF && (n || a))
    {
        double x, y;
        double pow2 = pow(a, 2.0);
        int valid = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &x, &y);

            double xp2 = pow(x, 2.0), yp2 = pow(y, 2.0);
            double xma = pow(x - a, 2.0), yma = pow(y - a, 2.0);
            
            if(xp2 + yp2 <= pow2
            && xp2 + yma <= pow2
            && xma + yp2 <= pow2
            && xma + yma <= pow2)
            {
                valid++;
            }
        }

        printf("%.5lf\n", (double)(valid) / (double)(n) * pow(a, 2));
    }

    return 0;
}
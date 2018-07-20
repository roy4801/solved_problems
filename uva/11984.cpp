/*
 * Uva 11984 - A Change in Thermal Unit
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11984.in", "r", stdin);
    freopen("./testdata/11984.out", "w", stdout);
    #endif
    int cases;
    float deg, f;

    scanf("%d", &cases);

    for(int i = 1; i <= cases && scanf("%f %f", &deg, &f) != EOF; i++)
    {
        float p = ((deg * 9.f / 5.f + 32.f + f) - 32.f) * 5.f / 9.f;
        
        printf("Case %d: %.2f\n", i, p);
    }

    return 0;
}
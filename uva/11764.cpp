/*
 * Uva 11764 - Jumping Mario
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11764.in", "r", stdin);
    freopen("./testdata/11764.out", "w", stdout);
    #endif
    int cases;
    int w;
    int pre, next;
    int high = 0, low = 0;

    scanf("%d", &cases);

    for(int i = 1; i <= cases && scanf("%d", &w) != EOF; i++)
    {
        printf("Case %d:", i);

        for(int a = 0; a < w && scanf("%d", &next) != EOF; a++)
        {
            if(a != 0 && next - pre > 0)
                high++;
            else if(a != 0 && next - pre < 0)
                low++;

            pre = next;
        }

        printf(" %d %d\n", high, low);
        high = low = 0;
    }

    return 0;
}
/*
 * Uva 661 - Blowing Fuses
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/661.in", "r", stdin);
    freopen("./testdata/661.out", "w", stdout);
    #endif
    int device, oper, limit;
    int time = 1;

    while(scanf("%d %d %d", &device, &oper, &limit) != EOF && device && oper && limit)
    {
        int power[device], now = 0, turn, max = 0;
        bool status = true;

        for(int i = 0; i < device; i++)
            scanf("%d", &power[i]);

        while(oper-- && scanf("%d", &turn) != EOF)
        {
            if(!status)
                continue;

            now += power[turn - 1];
            power[turn - 1] = -power[turn - 1];

            if(now > limit)
            {
                status = false;
                continue;
            }
            else if(now > max)
            {
                max = now;
            }
        }

        printf("Sequence %d\n", time++);
        printf("Fuse was%sblown.\n", status ? " not " : " ");
        if(status)
            printf("Maximal power consumption was %d amperes.\n", max);

        putchar('\n');
    }

    return 0;
}
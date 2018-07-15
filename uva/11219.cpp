/*
 * Uva 11219 - How old are you?
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11219.in", "r", stdin);
    freopen("./testdata/11219.out", "w", stdout);
    #endif
    int cases, t = 1;
    int ny, nm, nd;
    int by, bm, bd;

    scanf("%d", &cases);

    while(cases-- && scanf("%d/%d/%d", &nd, &nm, &ny) != EOF 
        && scanf("%d/%d/%d", &bd, &bm, &by) != EOF)
    {
        printf("Case #%d: ", t++);
        if(ny >= by)
        {
            if(ny > by)
            {
                if(ny - by > 130)
                {
                    if(ny - by == 131 && nm <= bm && nd < bd)
                    {
                        printf("%d\n", ny - by - 1);
                    }
                    else
                        printf("Check birth date\n");
                }
                // ny - by <= 130
                else
                {
                    if(nm < bm)
                    {
                        printf("%d\n", ny - by - 1);
                    }
                    else if(nm == bm)
                    {
                        if(nd < bd)
                        {
                            printf("%d\n", ny - by - 1);
                        }
                        else if(nd >= bd)
                        {
                            printf("%d\n", ny - by);
                        }
                    }
                    // nm > bm
                    else
                    {
                        printf("%d\n", ny - by);
                    }
                }
            }
            else if(ny == by)
            {
                if(nm < bm)
                {
                    printf("Invalid birth date\n");
                }
                else if(nm == bm)
                {
                    if(nd < bd)
                    {
                        printf("Invalid birth date\n");
                    }
                    else if(nd = bd)
                    {
                        printf("0\n");
                    }
                    // nd > bd
                    else
                    {
                        printf("%d\n", ny - by);
                    }
                }
                // nm > bm
                else
                {
                    printf("0\n");
                }
            }
        }
        else
        {
            printf("Invalid birth date\n");
        }

        // printf("%d %d %d\n%d %d %d\n\n", nd, nm, ny, bd, bm, by);
    }

    return 0;
}
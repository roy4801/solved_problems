/*
 * Uva 11942 - Lumberjack Sequencing
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

enum 
{
    Order_None,
    Order_Increasing,
    Order_Decreasing
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11942.in", "r", stdin);
    freopen("./testdata/11942.out", "w", stdout);
    #endif
    int cases;

    scanf("%d", &cases);

    printf("Lumberjacks:\n");
    while(cases--)
    {
        int order = Order_None;
        int pre, now;

        for(int i = 0; i < 10 && scanf("%d", &now) != EOF; i++)
        {
            // The second number will decide the order
            if(i == 1)
            {
                if(pre > now)
                    order = Order_Decreasing;
                else if(pre < now)
                    order = Order_Increasing;
            }
            else if(i > 1)
            {
                if( (order == Order_Decreasing && pre < now) || (order == Order_Increasing && pre > now) )
                {
                    order = Order_None;
                }
            }

            pre = now;
        }

        printf("%s\n", order == Order_None ? "Unordered" : "Ordered");
    }

    return 0;
}
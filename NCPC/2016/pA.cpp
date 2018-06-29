#include <iostream>

using namespace std;

int main()
{
    #ifdef DEBUG
    freopen("pA.in", "r", stdin);

    #endif
    int line;

    while(scanf("%d", &line) != EOF && line)
    {
        int sum = 0;

        for(int i = 1; i <= line; i++)
        {
            int tmp, max = 0;

            for(int a = 0; a < i; a++)
            {
                scanf("%d", &tmp);

                if(max < tmp)
                {
                    max = tmp;
                }
            }
            printf("%d\n", max);

            sum += max;
        }

        printf("sum: %d\n", sum);
    }

    return 0;
}
/*
 * Uva 11743 - Credit Check
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11743.in", "r", stdin);
    freopen("./testdata/11743.out", "w", stdout);
    #endif
    int cases;
    char in[6];

    scanf("%d", &cases);

    while(cases--)
    {
        int t = 0;
        int sum = 0;

        for(int i = 0; i < 4 && scanf("%s", in) != EOF; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                int n = in[j] - '0';

                // when j is even
                if(j % 2 == 0)
                {
                    n *= 2;

                    while(n > 9)
                    {
                        sum += n % 10;
                        n /= 10;
                    }
                }

                sum += n;
            }
        }

        if(sum % 10 == 0)
            printf("Valid\n");
        else
            printf("Invalid\n");

    }

    return 0;
}
/*
 * Uva 10929 - You can say 11
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

enum
{
    ADD_ODD,
    ADD_EVEN
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10929.in", "r", stdin);
    freopen("./testdata/10929.out", "w", stdout);
    #endif
    char in[1001];

    while(scanf("%s", in) != EOF && strcmp("0", in) != 0)
    {
        int l = strlen(in)-1;
        int nowState = ADD_ODD;
        int sum = 0;

        while(l >= 0)
        {
            // printf("now: %c\n", in[l]);
            if(nowState == ADD_ODD)
            {
                sum += in[l] - '0';
                nowState = ADD_EVEN;
            }
            else if(nowState == ADD_EVEN)
            {
                sum -= in[l] - '0';
                nowState = ADD_ODD;
            }
            l--;
        }
        // printf("o: %d e: %d\n", odd, even);
        // printf("%d\n", abs(odd - even));

        printf("%s is", in);
        if(abs(sum) % 11 != 0)
        {
            printf(" not");
        }
        printf(" a multiple of 11.\n");
    }

    return 0;
}
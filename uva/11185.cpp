/*
 * Uva 11185 - Ternary
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11185.in", "r", stdin);
    freopen("./testdata/11185.out", "w", stdout);
    #endif
    int num, i = 0;
    char ternary[21];

    while(scanf("%d", &num) != EOF && num >= 0)
    {
        while(num >= 3)
        {
            ternary[i++] = '0' + num % 3;

            num /= 3;
        }
        ternary[i++] = '0' + num;

        for(int a = i - 1; a >= 0; a--)
        {
            putchar(ternary[a]);
        }
        putchar('\n');

        i = 0;
    }

    return 0;
}

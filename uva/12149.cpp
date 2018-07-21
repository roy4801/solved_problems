/*
 * Uva 12149 - Feynman
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/12149.in", "r", stdin);
    freopen("./testdata/12149.out", "w", stdout);
    #endif
    int num;

    while(scanf("%d", &num) != EOF && num)
    {
        printf("%d\n", num * (num + 1) * (2 * num + 1) / 6); // sigma k^2
    }

    return 0;
}
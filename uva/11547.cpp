/*
 * Uva 11547 - Automatic Answer
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11547.in", "r", stdin);
    freopen("./testdata/11547.out", "w", stdout);
    #endif
    int cases, num;

    scanf("%d", &cases);

    while(cases-- && scanf("%d", &num) != EOF)
    {
        printf("%d\n", abs((315 * num + 36962) / 10 % 10));
    }

    return 0;
}
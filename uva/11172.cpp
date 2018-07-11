/*
 * Uva 11172 - Relational Operator
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11172.in", "r", stdin);
    freopen("./testdata/11172.out", "w", stdout);
    #endif
    int cases, a, b;

    scanf("%d", &cases);

    while(cases-- && scanf("%d %d", &a, &b) != EOF)
    {
        // The most hack code I have ever written
        printf("%c\n", (a - b > 0 ? '>' : (a - b < 0 ?  '<' : '=') ));
    }

    return 0;
}
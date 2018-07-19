/*
 * Uva 11936 - The Lazy Lumberjacks
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11936.in", "r", stdin);
    freopen("./testdata/11936.out", "w", stdout);
    #endif
    int cases, s[3];

    scanf("%d", &cases);

    while(cases-- && scanf("%d %d %d", &s[0], &s[1], &s[2]) != EOF)
    {
        sort(s, s + 3);

        if(s[0] + s[1] > s[2])
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }

    return 0;
}
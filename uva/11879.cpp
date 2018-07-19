/*
 * Uva 11879 - Multiple of 17
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isMultipleOf17(char num[])
{
    int len = strlen(num);
    int dividend = num[0] - '0';

    /* Simulate the long divison */
    for(int i = 1; i < len; i++)
    {
        dividend = dividend * 10 + num[i] - '0';

        dividend %= 17;
    }

    if(!dividend)
        return true;
    else
        return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11879.in", "r", stdin);
    freopen("./testdata/11879.out", "w", stdout);
    #endif
    char in[150];

    while(scanf("%s", in) != EOF && strcmp(in, "0") != 0)
    {
        if(isMultipleOf17(in))
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
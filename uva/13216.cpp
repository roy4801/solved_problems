/*
 * Uva 13216 - Problem with a ridiculously long name but with a ridiculously short description
 * author: roy4801
 * (C++)
 */
#include <iostream>
#include <cstring>

using namespace std;

int remainder[8];

void buildRTable()
{
    int x = 1;
    remainder[0] = 1;

    for(int i = 0; i < 7; i++)
    {
        x = (x * 66) % 100;
        remainder[i+1] = x;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/13216.in", "r", stdin);
    freopen("./testdata/13216.out", "w", stdout);
    #endif
    buildRTable();
    char num[1002];
    int cases;

    scanf("%d", &cases);

    while(cases-- && scanf("%s", num) != EOF)
    {
        int len = strlen(num);
        if(len == 1)
        {
            if(num[0] >= '0' && num[0] <= '6')
                printf("%d\n", remainder[num[0] - '0']);
            else if(num[0] >= '7' && num[0] <= '9')
                printf("%d\n", remainder[(num[0] - '0') % 7 + 2]);
        }
        else
            printf("%d\n", remainder[(num[len-1] - '0' + 3) % 5 + 2]);
    }

    return 0;
}
/*
 * Uva 10963 - The Swallowing Ground
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10963.in", "r", stdin);
    freopen("./testdata/10963.out", "w", stdout);
    #endif
    int cases, col, n, s;
    scanf("%d", &cases);

    while(cases-- && scanf("%d", &col) != EOF)
    {
        bool valid = true;
        int gap;
        for(int i = 0; i < col; i++)
        {
            scanf("%d %d", &n, &s);

            if(i == 0)
                gap = abs(n - s);
            else
            {
                if(gap != abs(n - s))
                {
                    valid = false;
                }
            }
        }

        printf("%s\n", valid ? "yes" : "no");

        if(cases != 0)
            putchar('\n');
    }

    return 0;
}
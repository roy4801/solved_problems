/*
 * Uva 12405 - Scarecrow
 * author: roy4801
 * (C++)
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/12405.in", "r", stdin);
    freopen("./testdata/12405.out", "w", stdout);
    #endif
    int cases, width, i = 1;

    scanf("%d", &cases);

    while(cases-- && scanf("%d ", &width) != EOF)
    {
        bool fertile[width];
        char c;
        int fsoil = 0, scarecrow = 0;

        printf("Case %d: ", i++);

        for(int i = 0; i < width && scanf("%c", &c) != EOF; i++)
        {
            // printf("Now: %c\n", c);
            if(c == '.')
            {
                fsoil++;
                fertile[i] = true;
            }
            else
                fertile[i] = false;
        }

        // printf("\nfsoil: %d\n", fsoil);

        for(int i = 0; i < width; i++)
        {
            
        }

        // printf("fsoil: %d\n", fsoil);
        scarecrow += fsoil > 0 ? 1 : 0;

        printf("%d\n", scarecrow);
    }

    return 0;
}
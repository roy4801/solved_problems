/*
 * Uva 12405 - Scarecrow
 * author: roy4801
 * AC(C++) 0.000
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
        int scarecrow = 0;

        printf("Case %d: ", i++);

        for(int i = 0; i < width; i++)
        {
            c = getchar(); // this is AC
            // scanf(" %c", &c);  // this is WA
            
            fertile[i] = (c == '.' ? true : false);
        }

        for(int i = 0; i < width; i++)
        {
            if(fertile[i])
            {
                fertile[i] = fertile[i + 1] = fertile[i + 2] = false;
                scarecrow++;
            }
        }

        printf("%d\n", scarecrow);

        /* AC */
        // char c;
        // int scarecrow = 0;

        // printf("Case %d: ", i++);

        // while((c = getchar()) != '\n' && c != EOF)
        // {
        //     if(c == '.')
        //     {
        //         scarecrow++;
        //         getchar();
        //         getchar();
        //     }
        // }

        // printf("%d\n", scarecrow);
    }

    return 0;
}
/*
 * Uva 10919 - Prerequisites?
 * author: roy4801
 * AC(C++) 0.030
 */
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10919.in", "r", stdin);
    freopen("./testdata/10919.out", "w", stdout);
    #endif
    int c, cat;

    while(scanf("%d %d", &c, &cat) != EOF && c)
    {
        int take[c];
        bool pass = true;

        for(int i = 0; i < c; i++)
            scanf("%d", &take[i]);

        int num, must;

        for(int i = 0; i < cat && scanf("%d %d", &num, &must) != EOF; i++)
        {
            // printf("%d %d\n", num, must);
            int courseInCat;

            for(int a = 0; a < num && scanf("%d", &courseInCat); a++)
            {
                for(int b = 0; b < c; b++)
                {
                    if(courseInCat == take[b])
                    {
                        must--;
                    }
                }
            }

            // One can choose >= must couses in a category
            if(must > 0)
            {
                pass = false;
            }
        }

        printf("%s\n", pass ? "yes" : "no");
    }

    return 0;
}
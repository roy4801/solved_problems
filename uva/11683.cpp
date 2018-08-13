/*
 * Uva 11683 - Laser Sculpture
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11683.in", "r", stdin);
    freopen("./testdata/11683.out", "w", stdout);
    #endif
    int w, h;

    while(scanf("%d %d", &h, &w) != EOF && h)
    {
        int remain, sculpt = 0;
        int empty = 0, prev;
        
        for(int i = 0; i < w && scanf("%d", &remain) != EOF; i++)
        {
            // previous number of scuplted blocks (init = 0)
            prev = empty;

            // number of scuplted block in i cloumn
            empty = h - remain;

            // the sculpting layer increases only when 
            // there are more blocks to be sculpted than previous cloumn
            sculpt += (empty - prev > 0 ? empty - prev : 0);
        }
        // result
        printf("%d\n", sculpt);
    }

    return 0;
}
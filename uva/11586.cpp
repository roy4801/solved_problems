/*
 * Uva 11586 - Train Tracks
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11586.in", "r", stdin);
    freopen("./testdata/11586.out", "w", stdout);
    #endif
    int cases;
    char c;

    scanf("%d ", &cases);

    while(cases--)
    {
        int sum = 0;
        bool space = false;

        while((c = getchar()) != EOF && c != '\n')
        {
            // skipping spaces
            if(c == ' ')
            {
                space = true;
            }
            else if(c == 'M')
            {
                sum++;
            }
            else if(c == 'F')
            {
                sum--;
            }
        }


        printf("%s\n", space && sum == 0 ? "LOOP" : "NO LOOP");
    }

    return 0;
}
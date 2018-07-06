/*
 * Uva 10789 - Prime Frequency
 * author: roy4801
 * AC(C++)  0.050
 */
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

#define MAX_PRIME_TABLE 2000
bool p[2001];

void initPrimeTable()
{
    for(int i = 0; i < MAX_PRIME_TABLE; i++)
        p[i] = true;

    p[0] = p[1] = false;
    for(int i = 2; i <= MAX_PRIME_TABLE; i++)
    {
        if(p[i])
        {
            for(int j = 2 * i; j <= MAX_PRIME_TABLE; j += i)
            {
                p[j] = false;
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10789.in", "r", stdin);
    freopen("./testdata/10789.out", "w", stdout);
    #endif
    initPrimeTable();

    char s[2001];
    int cases;

    scanf("%d", &cases);

    for(int i = 0; i < cases && scanf("%s", s) != EOF; i++)
    {
        printf("Case %d: ", i+1);

        int freq[CHAR_MAX+1] = {0}, primeTime = 0;

        for(int a = 0; a < strlen(s); a++)
        {
            freq[s[a]]++;
        }

        for(int c = 0; c < CHAR_MAX+1; c++)
        {
            if(p[freq[c]])
            {
                primeTime++;
                printf("%c", (char)c);
            }
        }

        if(!primeTime)
        {
            printf("empty");
        }
        putchar('\n');
    }

    return 0;
}
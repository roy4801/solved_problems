/*
 * Uva 10924 - Prime Words
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

#define MAX_PRIME 2000

bool prime[MAX_PRIME];

void buildPrimeTable()
{
    for(int i = 0; i < MAX_PRIME; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = true; // by the description of the problem

    for(int i = 2; i < MAX_PRIME; i++)
    {
        if(prime[i])
        {
            for(int j = i + i; j < MAX_PRIME; j += i)
                prime[j] = false;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10924.in", "r", stdin);
    freopen("./testdata/10924.out", "w", stdout);
    #endif
    buildPrimeTable();

    char word[21];

    while(scanf("%s", word) != EOF)
    {
        int sum = 0;

        char c, *p = word;

        while((c = *p++))
        {
            // printf("Now char: %c ", c);
            if(isupper(c))
            {
                sum += c - 'A' + 27;
            }
            else
            {
                sum += c - 'a' + 1;
            }
        }

        // printf("s: %d\n", sum);
        printf("%s\n", prime[sum] ? "It is a prime word." : "It is not a prime word.");
    }

    return 0;
}
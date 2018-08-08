/*
 * Uva 10424 - Love Calculator
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10424.in", "r", stdin);
    freopen("./testdata/10424.out", "w", stdout);
    #endif
    char name[2][26];
    int val[2] = {0};
    
    int n = 0;
    while(gets(name[n++]) != NULL && gets(name[n]) != NULL)
    {
        for(int i = 0; i < 2; i++)
        {
            for(int a = 0; a < strlen(name[i]); a++)
            {
                val[i] += isalpha(name[i][a]) ? tolower(name[i][a]) - 'a' + 1 : 0;
            }

            // 
            while(val[i] >= 10)
            {
                int tmp = 0;
                while(val[i] >= 10)
                {
                    tmp += val[i] % 10;
                    val[i] /= 10;
                }
                tmp += val[i];

                val[i] = tmp;
            }
        }

        printf("%.2f %\n", val[0] > val[1] ? 100.f * (float)val[1] / (float)val[0] : 100.f * (float)val[0] / (float)val[1]);
        val[0] = val[1] = n = 0;
    }

    return 0;
}
/*
 * Uva 12289 - One-Two-Three
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

const char* number[] = {"one", "two", "three"};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/12289.in", "r", stdin);
    freopen("./testdata/12289.out", "w", stdout);
    #endif
    char in[10];
    int cases;

    scanf("%d", &cases);

    while(cases-- && scanf("%s", in) != EOF)
    {
        int len = strlen(in), count = 0;
        
        for(int i = 0; i < 3; i++)
        {
            if(len == strlen(number[i]))
            {
                for(int j = 0; j < len; j++)
                {
                    if(in[j] == number[i][j])
                        count++;
                }

                if(count >= len - 1)
                {
                    printf("%d\n", i+1);
                    break;
                }
            }

            count = 0;
        }
    }

    return 0;
}
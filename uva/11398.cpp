/*
 * Uva 11398 - The Base-1 Number System
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11398.in", "r", stdin);
    freopen("./testdata/11398.out", "w", stdout);
    #endif
    char in[40];
    char binary[31];
    int now = 0;
    bool exit = false;

    while(true)
    {
        bool flag;
        int len;

        while(scanf("%s", in) && (strcmp("#", in) != 0 && (len = strlen(in))))
        {
            if(strcmp("~", in) == 0)
            {
                exit = true;
                break;
            }
            // flag
            if(len < 3)
            {
                if(strcmp("0", in) == 0)
                {
                    flag = true;
                }
                else if(strcmp("00", in) == 0)
                {
                    flag = false;
                }
            }
            // number
            else
            {
                for(int i = 0; i < len - 2; i++)
                    binary[now++] = flag ? '1' : '0';
            }
        }

        if(!exit)
        {
            binary[now] = '\0';
            
            int ans;
            ans = strtol(binary, NULL, 2);

            printf("%d\n", ans);

            now = 0;
        }
        else
            break;
    }
    return 0;
}
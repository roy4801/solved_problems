/*
 * Uva 11398 - The Base-1 Number System
 * author: roy4801
 * (C++)
 */
#include <iostream>

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

    while(scanf("%s", in) && strcmp("~", in) != 0)
    {
        bool flag;
        int len;

        while(scanf("%s", in) && strcmp("#", in) != 0 && (len = strlen(in)))
        {
            // flag
            if(len < 3)
            {
                if(strcmp("0", in) == 0)
                {
                    flag = false;
                }
                else if(strcmp("00", in) == 0)
                {
                    flag = true;
                }
            }
            // number
            else
            {
                for(int i = 0; i < len - 2; i++)
                    binary[now++] = flag ? '1' : '0';
            }
        }

        binary[now] = '\0';
        
        int ans;
        sscanf(binary, "%d", &ans);
    }
    return 0;
}
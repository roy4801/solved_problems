/*
 * Uva 10878 - Decode the Tape
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

enum
{
    READ_NONE,
    READ_START,
    READ_END
};

int binToChar(char b[])
{
    int sum = 0, idx = 7;
    for(int i = 1; i < 256; i *= 2)
    {
        sum += i * (b[idx--] - '0');
    }
    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10878.in", "r", stdin);
    freopen("./testdata/10878.out", "w", stdout);
    #endif
    char c;
    char nowChar[9];
    int now = 0;

    int state = READ_NONE;
    while((c = getchar()) != EOF)
    {
        if(c == '|')
        {
            if(state == READ_NONE || state == READ_END)
                state = READ_START;
            else if(state == READ_START)
            {
                state = READ_END;
                nowChar[now] = '\0';
                
                // printf("%s ", nowChar);
                putchar((char)binToChar(nowChar));
                // putchar('\n');

                now = 0;
            }

            // putchar('@');
        }
        else if(state == READ_START)
        {
            if(c != '.')
            {
                if(c == ' ')
                    nowChar[now++] = '0';
                else if(c == 'o')
                    nowChar[now++] = '1';
            }
        }
        // end of a tape
        else if(state == READ_END && c == '_')
        {
            state = READ_NONE;
        }
    }
    return 0;
}
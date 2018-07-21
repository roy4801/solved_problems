/*
 * Uva 12195 - Jingle Composing
 * author: roy4801
 * AC(C++) 0.010
 */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/12195.in", "r", stdin);
    freopen("./testdata/12195.out", "w", stdout);
    #endif
    char comp[202];

    while(fgets(comp, 202, stdin) != NULL)
    {
        int measure = 0;

        /* Get rid of that '\n' because of the fgets() */
        comp[strcspn(comp, "\n")] = '\0';

        if(strcmp(comp, "*") == 0)
            break;

        /* Practice string tokenize in C++       */
        /* I only record right border of a token */
        /* So it need to erase the original str  */
        std::string c = comp, token;
        std::string delim = "/";
        size_t pos;

        while((pos = c.find(delim)) != std::string::npos)
        {
            token = c.substr(0, pos);
            
            if(token != "")
            {
                int sumDur = 0;

                for(int i = 0; i < token.length(); i++)
                    switch(token[i])
                    {
                        case 'W':
                            sumDur += 64;
                        break;

                        case 'H':
                            sumDur += 32;
                        break;

                        case 'Q':
                            sumDur += 16;
                        break;

                        case 'E':
                            sumDur += 8;
                        break;

                        case 'S':
                            sumDur += 4;
                        break;

                        case 'T':
                            sumDur += 2;
                        break;

                        case 'X':
                            sumDur += 1;
                        break;
                    }

                measure += (sumDur == 64) ? 1 : 0;
                // printf("%d\n", sumDur % 64 == 0 ? sumDur / 64 : 0);
            }

            c.erase(0, pos + delim.length());
        }

        printf("%d\n", measure);
    }

    return 0;
}
#include <iostream>
#include <cstring>

struct Letter
{
    Letter()
    {
        ascii = num = 0;
    }
    Letter(const Letter &rhs)
    {
        ascii = rhs.ascii;
        num = rhs.num;
    }

    char ascii;
    int num;
};

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10062.in", "r", stdin);
    freopen("./testdata/10062.out", "w", stdout);
    #endif
    char str[1001], *p = str, c;
    int mapCharToInt[256];
    int nowLetter;
    bool first = true;

    while(fgets(str, 1001, stdin) != NULL)
    {
        if(first)
            first = false;
        else
            printf("\n\n");

        p = str;
        Letter l[256];
        bool f = true;

        for(int i = 0; i < 256; i++)
            mapCharToInt[i] = -1;
        nowLetter = 0;

        while((c = *p++) && c != '\n')
        {
            if(mapCharToInt[c] == -1)
            {
                mapCharToInt[c] = nowLetter++;
                l[mapCharToInt[c]].ascii = c;
            }

            l[mapCharToInt[c]].num++;
        }

        // sort
        for(int i = 0; i < 256; i++)
        {
            for(int j = i+1; j < 256; j++)
            {
                if(l[i].num > l[j].num)
                {
                    swap(l[i], l[j]);
                }
                else if(l[i].num == l[j].num)
                {
                    if(l[i].ascii < l[j].ascii)
                    {
                        swap(l[i], l[j]);
                    }
                }
            }
        }

        for(int i = 0; i < 256; i++)
        {
            if(l[i].num)
            {
                 if(f)
                    f = false;
                else
                    putchar('\n');

                printf("%d %d", l[i].ascii, l[i].num);
            }
        }
    }

    return 0;
}
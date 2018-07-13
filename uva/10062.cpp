/*
 * Uva 10062 - Tell me the frequencies!
 * author: roy4801
 * AC(C++) 0.000
 */
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

bool compareLetter(const Letter &lhs, const Letter &rhs)
{
    if(lhs.num < rhs.num)
    {
        return true;
    }
    else if(lhs.num == rhs.num)
    {
        return (lhs.ascii > rhs.ascii);
    }
}

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
            putchar('\n');

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

        sort(l, l + 256, compareLetter);

        for(int i = 0; i < 256; i++)
        {
            if(l[i].num)
            {
                printf("%d %d\n", l[i].ascii, l[i].num);
            }
        }
    }

    return 0;
}
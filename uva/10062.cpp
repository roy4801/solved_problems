#include <iostream>
#include <cstring>
// #include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/10062.in", "r", stdin);
    freopen("./testdata/10062.out", "w", stdout);
    #endif
    char str[1001], *p = s, c;
    int l[256] = {0};
    
    int nowLetter;

    while(fgets(str, 1000, stdin) != NULL)
    {
        nowLetter = 0;

        while((c = *p++) && c != '\n')
        {
            l[c]++;
        }

        for(int i = 0; i < 256; i++)
            if(l[i])
                nowLetter++;

        for(int i = 0; i < nowLetter; i++)
        {
            for(int j = 0; j < 256; j++)
            {
                
            }
        }

    }

    return 0;
}
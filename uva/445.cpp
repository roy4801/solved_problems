#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("445.in", "r", stdin);
    freopen("445.out", "w", stdout);
    #endif
    char line[100] = {0};
    bool first = true;
    char *last;
    int length;
    
    while(cin.getline(line, 100, '\n'))
    {
        int count = cin.gcount();
        // printf("%d\n", count);
        length = strlen(line);

        
        if(!first)
            putchar('\n');
        else
            first = false;

        char *ch = line;
        int num = 0;
        char c;

        // Parse the string
        while(*ch)
        {
            if(isdigit(*ch))
            {
                num += *ch - '0';
            }
            else
            {
                c = *ch;
                
                if(c == '!')
                {
                	last = ch;
                    putchar('\n');
                }
                else
                {
                    if(c == 'b')
                    {
                        c = ' ';
                    }

                    for(int i = 0; i < num; i++)
                    {
                        putchar(c);
                    }
                }
                num = 0;
            }
            ch++;
        }
    }

    // printf("%d %d %d\n", length, line + length - 1, last);

    if(line + length - 1 != last)
    	putchar('\n');
    
    return 0;
}
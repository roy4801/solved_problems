#include <iostream>
#include <cctype>

using namespace std;


int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("445.in", "r", stdin);
    freopen("445.out", "w", stdout);
    #endif
    char line[100] = {0};
    bool first = true;
    
    while(cin.getline(line, 100, '\n'))
    {
        int count = cin.gcount();
        printf("%d\n", count);
        
        if(count > 1)
        {
            if(!first)
                putchar('\n');
            else
                first = false;
            // cout << line << endl;
            //
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
        else
        {
            putchar('\n');
        }
    }
    putchar('\n');
    
    return 0;
}
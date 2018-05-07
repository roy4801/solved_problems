#include <iostream>

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("445.in", "r", stdin);
    freopen("445.out", "w", stdout);
    #endif
    char c;
    int num = 0;

    while((c = getchar()) && c != EOF)
    {
    	if(isdigit(c))
    	{
    		num += (c - '0');
    	}
    	else if(isgraph(c))// print
    	{
			if(c == '!')
			{
				putchar('\n');
				continue; // Go back
			}
			else if(c == 'b')
			{
				c = ' ';
			}
			
			for(int i = 0; i < num; i++)
			{
				putchar(c);
			}
			num = 0;
    	}
    	else if(c == '\n')// nextline
    	{
    		putchar('\n');
    	}
    }


	return 0;
}
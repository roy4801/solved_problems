#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/272.in", "r", stdin);
	freopen("./testdata/272.out", "w", stdout);
	#endif
	char str[1000];
	int quote = 0;

	while(fgets(str, 1000, stdin) != NULL)
	{
		char *now = str, c;

		while((c = *now++))
		{
			if(quote == 0 && c == '\"')
			{
				quote++;
				printf("``");
			}
			else if(quote > 0 && c == '\"')
			{
				printf("\'\'");
				quote--;
			}
			else
			{
				putchar(c);
			}
		}
	}
	return 0;
}
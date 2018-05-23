/*
 * Uva 11988 - Broken Keyboard (a.k.a. Beiju Text)
 * author: roy4801
 * AC(c++) 0.100
 */
#include <iostream>
#include <list>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11988.in", "r", stdin);
	freopen("./testdata/11988.out", "w", stdout);
	#endif
	char s[100001];
	char *now, c;
	
	while(scanf("%s", s) != EOF)
	{
		list<char> l;
		list<char>::iterator it = l.begin();
		now = s;

		while((c = *now++))
		{
			// cout << c << endl;
			if(c == '[')
			{
				it = l.begin();
			}
			else if(c == ']')
			{
				it = l.end();
			}
			else
			{
				l.insert(it, c);
			}
		}

		// getchar();

		for(it = l.begin(); it != l.end(); it++)
		{
			putchar(*it);
		}
		putchar('\n');
	}

	return 0;
}
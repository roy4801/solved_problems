/*
 * Uva 10222 - Decode the Mad man
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

map<char, char> m;

void initMap()
{
	m['\\'] = '[';
	m[']'] = 'p';
	m['['] = 'o';
	m['p'] = 'i';
	m['o'] = 'u';
	m['i'] = 'y';
	m['u'] = 't';
	m['y'] = 'r';
	m['t'] = 'e';
	m['r'] = 'w';
	m['e'] = 'q';
	m['\''] = 'l';
	m[';'] = 'k';
	m['l'] = 'j';
	m['k'] = 'h';
	m['j'] = 'g';
	m['h'] = 'f';
	m['g'] = 'd';
	m['f'] = 's';
	m['d'] = 'a';
	m['/'] = ',';
	m['.'] = 'm';
	m[','] = 'n';
	m['m'] = 'b';
	m['n'] = 'v';
	m['b'] = 'c';
	m['v'] = 'x';
	m['c'] = 'z';
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10222.in", "r", stdin);
	freopen("./testdata/10222.out", "w", stdout);
	#endif
	char c;

	initMap();

	while((c = tolower(getchar())) != EOF)
	{
		if(m[c])
		{
			putchar(m[c]);
		}
		else
			putchar(c);
	}

	return 0;
}
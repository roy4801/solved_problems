/*
 * Uva 10082 - WERTYU
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <map>

using namespace std;

char mapCharToChar[256];
// map<char, char> mapCharToChar;

void initMap()
{
	mapCharToChar['='] = '-';
	mapCharToChar['-'] = '0';
	mapCharToChar['0'] = '9';
	mapCharToChar['9'] = '8';
	mapCharToChar['8'] = '7';
	mapCharToChar['7'] = '6';
	mapCharToChar['6'] = '5';
	mapCharToChar['5'] = '4';
	mapCharToChar['4'] = '3';
	mapCharToChar['3'] = '2';
	mapCharToChar['2'] = '1';
	mapCharToChar['1'] = '`';
	mapCharToChar['\\'] = ']';
	mapCharToChar[']'] = '[';
	mapCharToChar['['] = 'P';
	mapCharToChar['P'] = 'O';
	mapCharToChar['O'] = 'I';
	mapCharToChar['I'] = 'U';
	mapCharToChar['U'] = 'Y';
	mapCharToChar['Y'] = 'T';
	mapCharToChar['T'] = 'R';
	mapCharToChar['R'] = 'E';
	mapCharToChar['E'] = 'W';
	mapCharToChar['W'] = 'Q';
	mapCharToChar['\''] = ';';
	mapCharToChar[';'] = 'L';
	mapCharToChar['L'] = 'K';
	mapCharToChar['K'] = 'J';
	mapCharToChar['J'] = 'H';
	mapCharToChar['H'] = 'G';
	mapCharToChar['G'] = 'F';
	mapCharToChar['F'] = 'D';
	mapCharToChar['D'] = 'S';
	mapCharToChar['S'] = 'A';
	mapCharToChar['/'] = '.';
	mapCharToChar['.'] = ',';
	mapCharToChar[','] = 'M';
	mapCharToChar['M'] = 'N';
	mapCharToChar['N'] = 'B';
	mapCharToChar['B'] = 'V';
	mapCharToChar['V'] = 'C';
	mapCharToChar['C'] = 'X';
	mapCharToChar['X'] = 'Z';
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10082.in", "r", stdin);
	freopen("./testdata/10082.out", "w", stdout);
	#endif
	initMap();
	char c;

	// printf("%d\n", sizeof(mapCharToChar));

	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n')
			putchar(c);
		else if(mapCharToChar[c])
			putchar(mapCharToChar[c]);
	}

	return 0;
}
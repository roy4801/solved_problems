/*
 * UVA 401 - Palindromes
 * author: roy4801
 * AC(C++)
 */
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<char, char> m;

bool isMirror(const char str[])
{
	int length = strlen(str);
	int half, same = 0;

	// Odd
	if(length % 2 != 0)
	{
		half = (length+1) / 2;
	}
	else
	{
		half = length / 2;
	}


	for(int i = 0; i < half; i++)
	{
		// std::cout << m[str[i]] << std::endl;
		if(m[str[i]] == str[length - 1 -i])
		{
			same++;
		}
	}

	if(length % 2 != 0 && same == half)
	{
		if(m[str[half - 1]] == str[half - 1])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(same == half)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void initMap()
{
	m['A'] = 'A';
	m['E'] = '3';
	m['H'] = 'H';
	m['I'] = 'I';
	m['J'] = 'L';
	m['L'] = 'J';
	m['M'] = 'M';
	m['O'] = 'O';
	m['S'] = '2';
	m['T'] = 'T';
	m['U'] = 'U';
	m['V'] = 'V';
	m['W'] = 'W';
	m['X'] = 'X';
	m['Y'] = 'Y';
	m['Z'] = '5';
	m['1'] = '1';
	m['2'] = 'S';
	m['3'] = 'E';
	m['5'] = 'Z';
	m['8'] = '8';
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/401.in", "r", stdin);
	freopen("./testdata/401.out", "w", stdout);
	#endif
	initMap();
	char str[100];

	while(scanf("%s", str) != EOF)
	{
		int length = strlen(str);
		int half, same = 0, mirror = 0, char_num = 0;

		// Odd
		if(length % 2 != 0)
		{
			half = (length + 1) / 2;
		}
		else
		{
			half = length / 2;
		}

		// std::cout << half << std::endl;

		for(int i = 0; i < half; i++)
		{
			if(str[i] == str[length - 1 -i])
			{
				same++;
			}
			// std::cout << m[str[i]] << ' ' << str[length - 1] << std::endl;
			if(m[str[i]] != 0 && m[str[i]] == str[length - 1 - i])
			{
				mirror++;
			}
			// if(isalpha(str[i]) && isalpha(str[length - 1 - i]))
			// 	char_num++;
		}

		// print result
		if(same == half)
		{
			if(mirror == half)
			{
				printf("%s -- is a mirrored palindrome.\n", str);
			}
			else
			{
				printf("%s -- is a regular palindrome.\n", str);
			}
		}
		else
		{
			if(mirror == half)
			{
				printf("%s -- is a mirrored string.\n", str);
			}
			else
			{
				printf("%s -- is not a palindrome.\n", str);
			}
		}
		putchar('\n');
	}

	return 0;
}
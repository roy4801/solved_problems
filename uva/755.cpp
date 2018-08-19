/*
 * Uva 755 - 487--3279
 * author: roy4801
 * (C++) 
 */
#include <iostream>
#include <cctype>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<char, char> letterToNum;

void initMap()
{
	letterToNum['A'] = letterToNum['B'] = letterToNum['C'] = '2';
	letterToNum['D'] = letterToNum['E'] = letterToNum['F'] = '3';
	letterToNum['G'] = letterToNum['H'] = letterToNum['I'] = '4';
	letterToNum['J'] = letterToNum['K'] = letterToNum['L'] = '5';
	letterToNum['M'] = letterToNum['N'] = letterToNum['O'] = '6';
	letterToNum['P'] = letterToNum['R'] = letterToNum['S'] = '7';
	letterToNum['T'] = letterToNum['U'] = letterToNum['V'] = '8';
	letterToNum['W'] = letterToNum['X'] = letterToNum['Y'] = '9';
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/755.in", "r", stdin);
	freopen("./testdata/755.out", "w", stdout);
	#endif
	initMap();

	int cases, phone;

	scanf("%d", &cases);

	while(cases-- && scanf("%d ", &phone) != EOF)
	{
		// map<string, int> strIdx;
		// vector<string> str;
		vector<int> times(1);

		vector<pair<string, int> > str;
		int now = 1;

		for(int i = 0; i < phone; i++)
		{
			char number[8], c, *p = number;

			while((c = getchar()) != EOF && c != '\n')
			{

				if(isalnum(c))
				{
					*p++ = isalpha(c) ? letterToNum[c] : c;
				}
			}
			*p = '\0';

			if(!strIdx[number])
				str.push_back(number);

			// add new to map and update number of str
			// addToMap(strIdx, times, number, now);

			// sort
			sort(str.begin(), str.end(), [&](const string lhs, const string rhs) -> bool
			{
				return stoi(lhs) < stoi(rhs);
			});
		}

		// for(int i = 1; i < times.size() && (~printf("%d\n", times[i])); i++);

		bool print = false;
		for(int i = 0; i < str.size(); i++)
		{
			int idx = strIdx[str[i]];

			if(times[idx] > 1)
			{
				str[i].insert(3, 1,'-');

				printf("%s ", str[i].c_str());

				str[i].erase(3, 1);

				printf("%d\n", times[idx]);
				print = true;
			}
		}

		if(!print)
			printf("No duplicates.\n");

		if(cases > 0)
			putchar('\n');

	}

	return 0;
}
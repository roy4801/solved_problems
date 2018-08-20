/*
 * Uva 755 - 487--3279
 * author: roy4801
 * AC(C++) 0.540
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
		map<string, int> strIdx;
		int now = 1;

		vector<pair<string, int> > str;

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

			// Add a phone number if it's first time
			if(!strIdx[number])
			{
				strIdx[number] = now++;
				str.push_back(pair<string, int>(number, 1));
			}
			// increment
			else
				str[strIdx[number]-1].second++;

			#if 0
			for(int i = 0; i < str.size() && (~printf("%d %s %d\n", i+1, str[i].first.c_str(), str[i].second)); i++);
			putchar('\n');
			#endif
		}
		
		// sort
		sort(str.begin(), str.end(), [&](const pair<string, int> lhs, const pair<string, int> rhs) -> bool
		{
			return stoi(lhs.first) < stoi(rhs.first);
		});

		// print phone number list with '-'
		bool print = false;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i].second > 1)
			{
				str[i].first.insert(3, 1,'-');

				printf("%s ", str[i].first.c_str());

				str[i].first.erase(3, 1);

				printf("%d\n", str[i].second);
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
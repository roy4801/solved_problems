/*
 * Uva 230 - Borrowers
 * author: roy4801
 * (C++) 
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

struct Book
{
	char title[81];
	char cat;
	bool borrow;

	Book()
	{
		title[0] = '\0';
		cat = 0;
		borrow = false;
	}
	Book(const char t[], const char c, bool b = false)
	{
		strcpy(title, t);
		cat = c;
		borrow = b;
	}
	//
	Book(const Book &other)
	{
		strcpy(title, other.title);
		cat = other.cat;
		borrow = other.borrow;
	}

	Book& operator=(const Book &other)
	{
		strcpy(title, other.title);
		cat = other.cat;
		borrow = other.borrow;

		return *this;
	}
	friend bool operator<(const Book &lhs, const Book &rhs)
	{
		return lhs.cat < rhs.cat ? (lhs.cat == rhs.cat && lhs.title[0] < rhs.title[0]) : false;
	}
};

void skipUntil(const char c, const int times = 1)
{
	int t = 0;
	char i;

	while(t++ < times)
		while((i = getchar()) != EOF && i != c);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/230.in", "r", stdin);
	freopen("./testdata/230.out", "w", stdout);
	#endif
	char c, tmp[81];
	vector<Book> list;
	map<string, int> m;
	bool input = true;

	while((c = getchar()) != EOF)
	{
		if(input)
			switch(c)
			{
				case '"':
				{
					int tmpIdx = 0;

					while((c = getchar()) && c != '"')
					{
						tmp[tmpIdx++] = c;
					}
					tmp[tmpIdx] = '\0';

					skipUntil(' ', 2);

					c = getchar();

					list.push_back(Book(tmp, c));

					skipUntil('\n');
				}
				break;

				case 'E':
					skipUntil('\n');
					input = false;
				break;
			}
		else
		{
			switch(c)
			{
				case 'B':
					skipUntil('"');


				break;

				case 'R':
					skipUntil('"');


				break;
			}
		}
	}

	sort(list.begin(), list.end());

	for(auto &i : list)
	{
		printf("%s %c\n", i.title, i.cat);
	}

	return 0;
}
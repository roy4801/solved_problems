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
	string title;
	string author;
	bool borrow, ret;

	Book(): title(), author()
	{
		borrow = ret = false;
	}

	Book(const char t[], const char a[], bool b = false, bool r = false) : title(t), author(a)
	{
		borrow = b;
		ret = r;
	}
	//
	Book(const Book &other)
	{
		title = other.title;
		author = other.author;
		borrow = other.borrow;
		ret = other.ret;
	}

	Book& operator=(const Book &other)
	{
		title = other.title;
		author = other.author;
		borrow = other.borrow;
		ret = other.ret;

		return *this;
	}
	friend bool operator<(const Book &lhs, const Book &rhs)
	{
		return lhs.author == rhs.author ? lhs.title < rhs.title : lhs.author < rhs.author;
	}
};

void skipUntil(const char c, const int times = 1)
{
	int t = 0;
	char i;

	while(t++ < times)
		while((i = getchar()) != EOF && i != c);
}

void readUntil(const char c, char str[])
{
	char i;
	int idx = 0;

	while((i = getchar()) != EOF && i != c)
	{
		str[idx++] = i;
	}
	str[idx] = '\0';
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
		int tmpIdx = 0;

		if(input)
			switch(c)
			{
				case '"':
				{
					char author[81];

					readUntil('"', tmp);

					skipUntil(' ', 2);

					tmpIdx = 0;

					readUntil('\n', author);

					// insert a book to the map
					m[tmp] = list.size();
					// push the book into the list
					list.push_back(Book(tmp, author));
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
				{
					skipUntil('"');

					readUntil('"', tmp);

					auto it = m.find(tmp);
					if(it != m.end())
					{
						list[it->second].borrow = true;
					}
					skipUntil('\n');
				}
				break;

				case 'R':
				{
					skipUntil('"');
					readUntil('"', tmp);

					auto it = m.find(tmp);
					if(it != m.end())
					{
						list[it->second].ret = true;
					}
					skipUntil('\n');
				}
				break;

				case 'S':
				{
					sort(list.begin(), list.end());
					skipUntil('\n');
					int b = 0;
					bool first = false;

					for(int i = 0; i < list.size(); i++)
						if(list[i].borrow)
							b++;
					// number of borrowed books == number of all books
					// means that the shelf is empty
					if(b == list.size())
						first = true;

					int onShelfIdx = -1;
					for(int i = 0; i < list.size(); i++)
					{
						// not borrowed
						if(!list[i].borrow)
						{
							onShelfIdx = i;
						}
						else if(list[i].ret)
						{
							printf("Put ");
							
							if(onShelfIdx != -1)
							{
								printf("\"%s\" after \"%s\"\n", list[i].title.c_str(), list[onShelfIdx].title.c_str());
							}
							else
							{
								printf("\"%s\" first\n", list[i].title.c_str());
							}
							list[i].borrow = list[i].ret = false;
							onShelfIdx = i;
						}
					}

					printf("END\n");
				}
				break;
			}
		}
	}

	// sort(list.begin(), list.end());

	// for(auto &i : list)
	// {
	// 	printf("%s %s %s %s\n", i.title.c_str(), i.author.c_str(), i.borrow ? "Borrowed" : "Not borrowed", i.ret ? "ret!" : "Not ret");
	// }

	return 0;
}
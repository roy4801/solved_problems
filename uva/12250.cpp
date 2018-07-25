/*
 * Uva 12250 - Language Detection
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>

using namespace std;

size_t BKDRHash(const char str[])
{
    size_t seed = 131;
    size_t hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

size_t word[6];
const char* lang[] =
{
	"ENGLISH",
	"SPANISH",
	"GERMAN",
	"FRENCH",
	"ITALIAN",
	"RUSSIAN"
};

void buildHashTable()
{
	word[0] = BKDRHash("HELLO");
	word[1] = BKDRHash("HOLA");
	word[2] = BKDRHash("HALLO");
	word[3] = BKDRHash("BONJOUR");
	word[4] = BKDRHash("CIAO");
	word[5] = BKDRHash("ZDRAVSTVUJTE");
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/12250.in", "r", stdin);
	freopen("./testdata/12250.out", "w", stdout);
	#endif
	buildHashTable();
	char str[15];
	int i = 1;

	while(scanf("%s", str) != EOF && strcmp(str, "#") != 0)
	{
		printf("Case %d: ", i++);

		bool found = false;
		size_t h = BKDRHash(str);

		for(int i = 0; i < 6; i++)
		{
			if(word[i] == h)
			{
				printf("%s\n", lang[i]);
				found = true;
				break;
			}
		}

		if(!found)
			printf("%s\n", "UNKNOWN");
	}

	return 0;
}
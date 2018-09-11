#include <iostream>

using namespace std;

unsigned int BKDRHash(const char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

const char* str[] = {"Hi", "Hello", "How do you do", "How are you"};
size_t strHash[4];

void buildHash()
{
	for(int i = 0; i < 4; i++)
	{
		strHash[i] = BKDRHash(str[i]);
	}
}

int main()
{
	#ifdef DBG
	freopen("p3.in", "r", stdin);
	freopen("p3.out", "w", stdout);
	#endif
	buildHash();
	int now = 0;
	char ch[100];

	while(fgets(ch, 100, stdin) != NULL)
	{
		ch[strcspn(ch, "\n")] = '\0';
		size_t h = BKDRHash(ch);
		bool print = false;

		for(int i = 0; i < 4; i++)
		{
			if(h == strHash[i])
			{
				printf("%s\n", str[now++]);
				now %= 4;
				print = true;

				break;
			}
		}

		if(!print)
		{
			printf("%s\n", "Sorry");
			now = 0;
		}
	}

	return 0;
}
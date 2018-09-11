#include <iostream>

using namespace std;

bool p[1005];

void sieve()
{
	memset(p, true, sizeof(p));

	p[1] = false;

	for(int i = 2; i <= 1000; i++)
	{
		if(p[i])
		{
			for(int j = i * 2; j <= 1000; j += i)
				p[j] = false;
		}
	}
}

int getUpperPrime(const int limit)
{
	for(int i = limit; i >= 0; i--)
	{
		if(p[i])
			return i;
	}
}

int main()
{
	#ifdef DBG
	freopen("p2.in", "r", stdin);
	freopen("p2.out", "w", stdout);
	#endif
	sieve();
	int limit;

	while(scanf("%d", &limit) != EOF)
	{
		printf("%d\n", getUpperPrime(limit));
	}
	return 0;
}
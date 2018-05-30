/*
 * Uva 686 - Goldbach's Conjecture (II)
 * author: roy4801
 * AC(c++) 0.000
 */
#include <iostream>

using namespace std;

#define TABLE_SIZE 33000

bool prime[TABLE_SIZE];

void buildPrimeTable()
{
	prime[0] = prime[1] = false;
	for(int i = 2; i < TABLE_SIZE; i++)
		prime[i] = true;

	for(int i = 2; i < TABLE_SIZE; i++)
	{
		if(prime[i])
			for(int a = 2*i; a < TABLE_SIZE; a += i)
				prime[a] = false;
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/686.in", "r", stdin);
	freopen("./testdata/686.out", "w", stdout);
	#endif
	buildPrimeTable();
	
	int num;

	while(scanf("%d", &num) != EOF && num != 0)
	{
		int count = 0;

		for(int i = 2; i <= num/2; i++)
		{
			if(prime[i] && prime[num-i]) count++;
		}

		printf("%d\n", count);
	}

	return 0;
}
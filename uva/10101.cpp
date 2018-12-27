/*
 * Uva 10101 - Bangla Numbers
 * author: roy4801
 * (C++)
 */
#include <iostream>

using namespace std;

typedef long long int int_64;

char unit[][6] = {"shata", "hajar", "lakh", "kuti"};
int limit[4] = {100, 10, 100, 100};
bool first = true;

void print(int_64 num, int judge)
{
	
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10101.in", "r", stdin);
	freopen("./testdata/10101.out", "w", stdout);
	#endif
	int_64 n;
	int times = 1;

	while(scanf("%lld", &n) != EOF)
	{
		printf("%4d. ", times++);
		print(n, 0);
		first = true; // reset
		putchar('\n');
	}

	return 0;
}
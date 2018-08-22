#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

enum Gacha_type
{
	G_SINGLE,
	G_MULTI
};

enum State
{
	S_NONE,
	S_SINGLE,
	S_MULTI
};

bool judge(int perm[], const int size, const int contiSingle, const int singleGacha, const int multiGacha, const int numMulti)
{
	int single = 0;
	int state = S_NONE;
	bool pass = true;

	for(int i = 0; i < size; i++)
	{
		if(perm[i] == G_SINGLE)
		{
			single++;

			state = S_SINGLE;
		}
		else if(perm[i] == G_MULTI)
		{
			if(state == S_SINGLE)
			{
				if(single > contiSingle)
				{
					pass = false;
					break;
				}
				single = 0;
			}

			state = S_MULTI;
		}
	}

	if(single > contiSingle)
		pass = false;

	return pass;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	#endif
	int multiGacha, numMulti;
	int singleGacha, contiSingle;

	while(scanf("%d %d %d %d", &multiGacha, &singleGacha, &numMulti, &contiSingle) != EOF)
	{
		const int c = multiGacha * numMulti + singleGacha;
		int europe[c];

		// Input europe points
		for(int i = 0; i < c && scanf("%d", &europe[i]) != EOF; i++);

		#if 0
		// for(int i = 0; i < c && (~printf("%d ", europe[i])); i++);
		// putchar('\n');
		#endif
		const int size = singleGacha + numMulti;
		int max = 0;
		int first[numMulti];
		int perm[size];

		// init perm array
		for(int i = 0; i < singleGacha; i++)
			perm[i] = G_SINGLE;
		for(int i = singleGacha; i < numMulti + singleGacha; i++)
			perm[i] = G_MULTI;

		// Find comb that is max europe point
		do
		{
			if(judge(perm, size, contiSingle, singleGacha, multiGacha, numMulti))
			{
				int tmp = 0, tmpIdx[numMulti], now = 0, nowMulti = 0;

				// Gacha!
				for(int i = 0; i < size; i++)
				{
					// printf("%d %d %d \n", perm[i], europe[now], now);
					if(perm[i] == G_SINGLE)
					{
						tmp += europe[now++];
					}
					else if(perm[i] == G_MULTI)
					{
						tmp += europe[now];
						
						tmpIdx[nowMulti++] = now+1;
						
						now += multiGacha;
					}
				}

				#if 0
				for(int i = 0; i < size; i++)
					printf(i != size-1 ? "%d " : "%d\n", perm[i]);
				printf("%d\n\n", tmp);
				#endif

				if(max < tmp)
				{
					max = tmp;
					for(int i = 0; i < numMulti; i++)
					{
						first[i] = tmpIdx[i];
					}
				}
			}
		}
		while(next_permutation(perm, perm + size));

		// print max europe point
		printf("%d\n", max);
		for(int i = 0; i < numMulti; i++)
			printf(i != numMulti-1 ? "%d " : "%d\n", first[i]);
	}
	return 0;
}
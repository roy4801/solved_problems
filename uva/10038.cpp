/*
 * Uva 10038 - Jolly Jumpers
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10038.in", "r", stdin);
	freopen("./testdata/10038.out", "w", stdout);
	#endif
	int num;

	while(scanf("%d", &num) != EOF)
	{
		int seq[num];
		bool diff[num], print = true;

		for(int i = 0; i < num; i++)
		{
			diff[i] = false;
			scanf("%d", &seq[i]);
		}

		for(int i = 0; i < num - 1; i++)
		{
			int judge = abs(seq[i] - seq[i+1]);

			if(judge > num - 1)
			{
				print = false;
				goto exit; // GOTO Line 47 means that a loop is end due to difference between two adjacent number > num - 1
			}
			else
				diff[judge] = true;
		}

		for(int i = 1; i < num; i++)
		{
			if(!diff[i])
			{
				print = false;
				break;
			}
		}

exit:
		if(print)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}

	return 0;
}
/*
 * Uva 10107 - What is the Median?
 * author: roy4801
 * AC(C++) 0.710
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10107.in", "r", stdin);
	freopen("./testdata/10107.out", "w", stdout);
	#endif
	int now = 0;
	int arr[10000];
	
	while(scanf("%d", &arr[now]) != EOF)
	{
		now++;

		if(now == 1)
		{
			printf("%d\n", arr[0]);
		}
		else if(now == 2)
		{
			printf("%d\n", (arr[0] + arr[1]) / 2);
		}
		else
		{
			sort(arr, arr + now);

			if(now % 2 != 0)
			{
				printf("%d\n", arr[(now-1) / 2]);
			}
			else
			{
				printf("%d\n", (arr[(now-1) / 2] + arr[(now-1) / 2 + 1]) / 2);
			}
		}
	}

	return 0;
}
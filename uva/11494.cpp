/*
 * Uva 11494 - Queen
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/11494.in", "r", stdin);
	freopen("./testdata/11494.out", "w", stdout);
	#endif
	int start[2], end[2];

	while(scanf("%d %d %d %d", &start[0], &start[1], &end[0], &end[1]) != EOF && (start[0] || start[1] || end[0] || end[1]))
	{
		int left[2] = { start[0] + start[1]
						, end[0] + end[1]	};
		int right[2] = { start[1] >= start[0] ? 7 - (start[1]-start[0]) : 7 + (start[0]-start[1])
						, end[1] >= end[0] ? 7 - (end[1]-end[0]) : 7 + (end[0]-end[1])				};
		
		if(start[0] == end[0] && start[1] == end[1])
			printf("0\n");
		else if(start[0] == end[0] || start[1] == end[1] || left[0] == left[1] || right[0] == right[1])
			printf("1\n");
		else
			printf("2\n");
	}

	return 0;
}
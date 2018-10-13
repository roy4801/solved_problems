/*
 * Uva 145 - Gondwanaland Telecom
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

enum
{
	HOUR,
	MINUTE
};

#define MAX_MIN 1440

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/145.in", "r", stdin);
	freopen("./testdata/145.out", "w", stdout);
	#endif
	char type, phone[10];
	int start[2], end[2];
	const float plan[5][3] = {{0.1f, 0.06f, 0.02f},
							  {0.25f, 0.15f, 0.05f},
							  {0.53f, 0.33f, 0.13f},
							  {0.87f, 0.47f, 0.17f},
							  {1.44f, 0.8f, 0.3f}};
	
	while(scanf("%c ", &type) != EOF && type != '#')
	{
		bool onPhone[MAX_MIN] = {false};

		scanf("%s %d %d %d %d ", phone, &start[HOUR], &start[MINUTE], &end[HOUR], &end[MINUTE]);

		int s = start[HOUR] * 60 + start[MINUTE] // start min
		, e = end[HOUR] * 60 + end[MINUTE];      // end min

		int period[3] = {0};
		float fee = 0.f;

		// Fill the onPhone[]
		if(s < e)
			for(int i = s; i < e; i++)
				onPhone[i] = true;
		else if(s > e)
		{
			for(int i = s; i < MAX_MIN; i++)
				onPhone[i] = true;
			for(int i = 0; i < e; i++)
				onPhone[i] = true;
		}
		else
		{
			fill(onPhone, onPhone + MAX_MIN, true);
		}
			
		
		for(int i = 0; i < MAX_MIN; i++)
		{
			if(onPhone[i])
			{
				if(i >= 480 && i < 1080) // A
					period[0]++;
				if(i >= 1080 && i < 1320) // B
					period[1]++;
				if((i >= 0 && i < 480) || (i >= 1320 && i < MAX_MIN)) // C
					period[2]++;
			}
		}
		

		// Calc
		for(int i = 0; i < 3; i++)
			fee += (float)period[i] * plan[type - 'A'][i];

		// Print
		printf("%10s%6d%6d%6d%3c%8.2f\n", phone, period[0], period[1], period[2], type, fee);
	}

	return 0;
}
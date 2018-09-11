#include <iostream>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("p1.in", "r", stdin);
	freopen("p1.out", "w", stdout);
	#endif
	int cases, score[3];

	scanf("%d", &cases);

	while(cases-- && scanf("%d %d %d", &score[0], &score[1], &score[2]) != EOF)
	{
		int sum = score[0] + score[1] + score[2];
		int bigger = 0;
		bool gre80 = false;

		for(int i = 0; i < 3; i++)
		{
			if(score[i] >= 60)
				bigger++;
			if(score[i] >= 80)
				gre80 = true;
		}

		if(bigger == 3)
			putchar('P');
		else if(bigger == 2)
		{
			if(sum >= 220)
				putchar('P');
			else
				putchar('M');
		}
		else if(bigger == 1 && gre80)
			putchar('M');
		else
			putchar('F');
		putchar('\n');
	}

	return 0;
}
#include <iostream>

int digitSquareSum(int num)
{
	int rt = 0;

	while(num > 9)
	{
		rt += (num % 10) * (num % 10);
		num /= 10;
	}
	rt += num * num;

	return rt;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10591.in", "r", stdin);
	freopen("./testdata/10591.out", "w", stdout);
	#endif
	int cases;

	if(scanf("%d", &cases) != EOF)
	{
		int num;
		int c = 1;// cases print
		bool unhappyFlag = false;

		while(cases-- && scanf("%d", &num) != EOF)
		{
			int tur = num, rab = num;

			// Find a loop (龜兔算法) ref: Floyd判圈算法
			
			while(true)
			{
				tur = digitSquareSum(tur);
				if(tur == 1)
				{
					// printf("JMP\n");
					unhappyFlag = false;
					break;
				}

				rab = digitSquareSum(digitSquareSum(rab));
				if(rab == 1)
				{
					// printf("JMP\n");
					unhappyFlag = false;
					break;
				}

				if(tur == rab)
				{
					unhappyFlag = true;
					break;
				}
				// printf("%d %d\n", tur, rab);
			}

			printf("Case #%d: %d is ", c++, num);
			printf("%s number.\n", unhappyFlag ? "an Unhappy" : "a Happy");
			unhappyFlag = false;
		}
	}
	return 0;
}
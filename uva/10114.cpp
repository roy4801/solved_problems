/*
 * Uva 10114 - Loansome Car Buyer
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/10114.in", "r", stdin);
	freopen("./testdata/10114.out", "w", stdout);
	#endif
	int month, rec;
	double downPay, loan;

	while(scanf("%d", &month) != EOF && month > 0
		&& scanf("%lf %lf %d", &downPay, &loan, &rec) != EOF)
	{
		double value = loan + downPay;
		double pay = loan / month;
		double curDep;
		int minimum = 0;

		int depIdx[month];
		double dep[rec];

		// init
		for(int i = 0; i < month; i++)
			depIdx[i] = -1;

		// get the depriciation records
		for(int i = 0; i < rec; i++)
		{
			int tmp;
			scanf("%d %lf", &tmp, &dep[i]);

			depIdx[tmp] = i;
		}

		// simulates the paying loan
		for(int i = 0; i < month; i++)
		{
			// whether to update the curDep or not
			if(depIdx[i] != -1)
				curDep = 1.0 - dep[depIdx[i]];
			
			value *= curDep;

			// printf("%d: %lf %lf\n", i, value, loan);
			if(value > loan)
			{
				break;
			}

			minimum++;
			loan -= pay;
		}

		if(minimum != 1)
		{
			printf("%d months\n", minimum);
		}
		else
			printf("1 month\n");
	}

	return 0;
}
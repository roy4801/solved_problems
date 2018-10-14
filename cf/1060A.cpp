/*
 * CF 1060A - Phone Numbers
 * author: roy4801
 * AC(C++)
 */
#include <iostream>

using namespace std;

#define PROB "1060A"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int len;

	while(scanf("%d ", &len) != EOF)
	{
		int eig = 0;
		int not_eig = 0;
		char c;

		for(int i = 0; i < len; i++)
		{
			c = getchar();

			if(c != '8')
			{
				not_eig++;
			}
			else
			{
				eig++;
			}
		}

		// printf("%d %d\n", eig, not_eig);
		printf("%d\n", min(eig, (not_eig + eig) / 11));
	}

	return 0;
}
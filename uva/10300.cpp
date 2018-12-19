/*
 * Uva 10300 - Ecological Premium
 * author: roy4801
 * AC(C++)
 */
#include <iostream>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("10300.in", "r", stdin);
	freopen("10300.out", "w", stdout);	
	#endif
	
	int test_case;
	while(cin >> test_case)
	{
		for(int i = 0; i < test_case; i++)
		{
			int farm_case;
			long long int budget = 0LL;
			
			if(cin >> farm_case)
			{
				for(int j = 0; j < farm_case; j++)
				{
					float size, animal, d_eco;
					if(cin >> size >> animal >> d_eco)
					{
						// calc profit
						budget += static_cast<long long>(size * d_eco); // cannot AC in udebug
					}
				}
			}
			cout << budget << endl;
		}
	}
	return 0;
}

/*
 * Uva 514 - Rails
 * author: roy4801
 * AC(c++) 0.040
 */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/514.in", "r", stdin);
	freopen("./testdata/514.out", "w", stdout);
	#endif
	int num;

	while(scanf("%d", &num) != EOF && num != 0)
	{
		int in[num];
		bool exit = false;

		while(true)
		{
			// input sequence of cart in B
			for(int i = 0; i < num; i++)
			{
				scanf("%d", &in[i]);
				if(in[i] == 0)
				{
					exit = true;
					break;
				}
			}
			
			// If seq B contains any 0
			if(exit)
			{
				break;
			}
			else
			{
				stack<int> s;
				int now = 0, permu = 1;

				for(;;)
				{
					s.push(permu++);
					
					while(!s.empty() && s.top() == in[now])
					{
						// printf("%d ", s.top());
						s.pop();
						now++;
					}

					if(permu > num && (s.empty() || s.top() != in[now]) ) // order is important (shortcut operation)
						break;
				}

				if(s.empty())
				{
					printf("Yes\n");
				}
				else
				{
					printf("No\n");
				}
			}
		}
		putchar('\n');
	}

	return 0;
}
/*
 * UVA 402 - M*A*S*H
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "402"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define N 50
int n, luck;
int d[20];
vector<int> ans;
bool valid[N+5];
int len;
bool early;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int kase = 1;
	while(cin >> n >> luck)
	{
		// init
		ans.clear();
		memset(valid, true, sizeof(valid));
		len = n;
		early = false;
		// input
		for(int i = 0; i < 20 && cin >> d[i]; i++);

		int j = 1;
		for(int i = 0; i < 20; i++)
		{
			int cnt = 0;
			while(j <= n)
			{
				if(valid[j])
					cnt++;
				if(cnt == d[i])
				{
					valid[j] = false;
					cnt = 0;
					len--;

					if(len <= luck)
						goto print;
				}
				j++;
			}

			j = 1;
			// for(int i = 1; i <= n; i++)
			// 	printf("%3d", i);
			// puts("");
			// for(int i = 1; i <= n; i++)
			// 	printf("%3c", valid[i]?' ':'X');
			// puts("");
			// printf("len=%d\n", len);
			// puts("------------------------------");
		}

print:
		for(int i = 1; i <= n; i++)
			if(valid[i])
				ans.push_back(i);
		cout << "Selection #" << kase++ << '\n';
		for(int i = 0; i < ans.size(); i++)
			printf(i<ans.size()-1?"%d ":"%d\n", ans[i]);
		putchar('\n');
	}
	return 0;
}
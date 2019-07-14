/*
 * UVA 340 - Master-Mind Hints
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "340"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define N 1000
int in[N+5], ans[N+5], ansc[10], tmp[10];
bool ex, check[N+5];
int n, a, b, kase = 1;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> n && n)
	{
		printf("Game %d:\n", kase++);
		memset(ansc, 0, sizeof(ansc));

		for(int i = 0; i < n && cin >> ans[i]; i++)
			ansc[ans[i]]++;

		while(true)
		{
			memset(check, 0, sizeof(check));
			ex = true;
			a = b = 0;
			for(int i = 0; i < 10; i++) tmp[i] = ansc[i];
			//
			for(int i = 0; i < n && cin >> in[i]; i++)
				if(in[i]) ex = false;
			// calc A
			for(int i = 0; i < n; i++)
				if(in[i] == ans[i])
					a++, tmp[ans[i]]--, check[i] = true;
			// calc B
			for(int i = 0; i < n; i++)
				if(!check[i])
					if(tmp[in[i]])
						b++, tmp[in[i]]--;

			if(ex) break;
			else
				printf("    (%d,%d)\n", a, b);
		}
	}

	return 0;
}
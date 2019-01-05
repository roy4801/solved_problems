/*
 * UVA 10178 - Count the Faces.
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10178"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

// naked disjoint set

#define N 53
int p[N];

void init()
{
	for(int i = 0; i < N; i++)
		p[i] = i;
}
int find(int x)
{
	return x==p[x]?x:(p[x]=find(p[x]));
}
void uni(int a, int b)
{
	p[find(a)] = find(b);
}
int n, m;
char ctoi(char in)
{
	if(isupper(in))
	{
		in -= 'A';
		in += 26;
	}
	else
		in -= 'a';
	return in;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	char a, b;
	while(cin >> n >> m)
	{
		init();
		int cnt = 1;

		for(int i = 0; i < m && cin >> a >> b; i++)
		{
			a = ctoi(a);
			b = ctoi(b);
			// printf("%d %d\n", a, b);

			if(find(a) == find(b))
			{
				// cout << ">> IN" << '\n';
				cnt++;
			}
			uni(a, b);
		}
		cout << cnt << '\n';
	}

	return 0;
}
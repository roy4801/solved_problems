/*
 * UVA 352 - The Seasonal War
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "352"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int n;
bool mm[26][26] = {false};

void dfsn(int x, int y)
{
	mm[x][y] = false;

	if(x > 0)
	{
		// Left
		if(mm[x-1][y])
			dfsn(x-1, y);
		
		// Left Up
		if(y > 0 && mm[x-1][y-1])
			dfsn(x-1, y-1);
		
		// Left Down
		if(y < n && mm[x-1][y+1])
			dfsn(x-1, y+1);
	}
	if(x < n)
	{
		// Right
		if(mm[x+1][y])
			dfsn(x+1, y);
		
		// Right Up
		if(y > 0 && mm[x+1][y-1])
			dfsn(x+1, y-1);
		
		// Right Down
		if(y < n && mm[x+1][y+1])
			dfsn(x+1, y+1);
	}
	// Up
	if(y > 0 && mm[x][y-1])
		dfsn(x, y-1);
	// Down
	if(y < n && mm[x][y+1])
		dfsn(x, y+1);
}

int dfs()
{
	int grp = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(mm[i][j])
			{
				dfsn(i, j);
				grp++;
			}
	return grp;
}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	USE_CPPIO();
	int kase = 1;

	while(cin >> n)
	{
		cin.ignore(1);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				mm[i][j] = cin.get() == '1' ? true : false;
			cin.get();
		}

		// dfs
		// printf("%d\n", dfs());
		printf("Image number %d contains %d war eagles.\n", kase++, dfs());

		memset(mm, false, sizeof(mm));
	}

	return 0;
}
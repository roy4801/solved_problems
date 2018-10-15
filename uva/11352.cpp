/*
 * UVA 11352 - Crazy King
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "11352"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int m, n;
int sp[2], ep[2];
int mm[105][105];
queue<pair<int, int> > que;

#define GG(x, y) que.push(make_pair((x), (y)))

bool notBarr(char c)
{
	return c != 'Z' && c != 'x' && c != 'A';
}

bool go()
{
	int i = que.front().first, j = que.front().second;
	// if touch end
	if(i == ep[0] && j == ep[1])
		return true;
	else
		mm[i][j] = 'A';

	// Left
	if(j > 0)
	{
		// Left
		if(notBarr(mm[i][j-1]))
			GG(i, j-1);
	}
	// Right
	if(j < n)
	{
		// Right
		if(notBarr(mm[i][j+1]))
			GG(i, j+1);

		// Right Up
		if(i > 0 && notBarr(mm[i-1][j+1]))
			GG(i-1, j+1);
		// Right Down
		if(i < m && notBarr(mm[i+1][j+1]))
			GG(i+1, j+1);
	}
	// Up
	if(i > 0 && notBarr(mm[i-1][j]))
		GG(i-1, j);
	// Down
	if(i < m && notBarr(mm[i+1][j]))
		GG(i+1, j);

	return false;
}

int bfs(int m, int n)
{
	int step = 0;
	bool found;
	que.push(make_pair(sp[0], sp[1]));

	while(!que.empty())
	{
		step++;

		found = go();
		que.pop();
	}

	return found ? step : 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	USE_CPPIO();

	int Case;
	char c;

	scanf("%d", &Case);
	while(Case-- && scanf("%d %d ", &m, &n) != EOF)
	{
		// Input
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				c = getchar();

				mm[i][j] = c;
			}
			getchar();
		}

		// Possible horse move
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
			{
				if(mm[i][j] == 'Z')
				{
					if(i > 2)
					{
						// left up
						if(j > 2 && mm[i-2][j-2] != 'Z')
							mm[i-2][j-2] = 'x';
						// right up
						if(j < n -2 && mm[i-2][j+2] != 'Z')
							mm[i-2][j+2] = 'x';
					}
					if(i < n-2)
					{
						// left down
						if(j > 2 && mm[i+2][j-2] != 'Z')
							mm[i+2][j-2] = 'x';
						// right down
						if(j < n - 2 && mm[i+2][j+2]  != 'Z')
							mm[i+2][j+2] = 'x';
					}
				}
				else if(mm[i][j] == 'A')
				{
					sp[0] = i;
					sp[1] = j;
				}
				else if(mm[i][j] == 'B')
				{
					ep[0] = i;
					ep[1] = j;
				}
			}

		#if 0
		printf("%d %d | %d %d\n", sp[0], sp[1], ep[0], ep[1]);
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				putchar(mm[i][j]);
			}
			putchar('\n');
		}
		#endif

		// King walk
		int step = bfs(m, n);

		if(!step)
			printf("King Peter, you can't go now!\n");
		else
			printf("Minimal possible length of a trip is %d\n", step);
		//
		//
		#if 0
		printf("%d %d | %d %d\n", sp[0], sp[1], ep[0], ep[1]);
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				putchar(mm[i][j]);
			}
			putchar('\n');
		}
		#endif

		memset(mm, 0, sizeof(mm));
	}


	return 0;
}
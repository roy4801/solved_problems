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



inline bool notBarr(char c)
{
	return c != 'Z' && c != 'x' && c != 'A';
}

inline bool canPlace(char c)
{
	return c == '.';
}

int nowStep = 0;
bool touchEnd = false;

void GG(int x, int y)
{
	que.push(make_pair(x, y));

	if(isdigit(mm[x][y]))
	{
		if(mm[x][y] - '0' > nowStep)
			mm[x][y] = '0' + nowStep;
	}
	else
		mm[x][y] = '0' + nowStep;
}

void go()
{
	nowStep++;

	int i = que.front().first, j = que.front().second;

	// Left
	if(j > 0)
	{
		// Left
		if(notBarr(mm[i][j-1]))
			GG(i, j-1);
		// Left up
		if(i > 0 && notBarr(mm[i-1][j-1]))
			GG(i-1, j-1);
		// Left down
		if(i < m-1 && notBarr(mm[i+1][j-1]))
			GG(i+1, j-1);
	}
	// Right
	if(j < n-1)
	{
		// Right
		if(notBarr(mm[i][j+1]))
			GG(i, j+1);

		// Right Up
		if(i > 0 && notBarr(mm[i-1][j+1]))
			GG(i-1, j+1);
		// Right Down
		if(i < m-1 && notBarr(mm[i+1][j+1]))
			GG(i+1, j+1);
	}
	// Up
	if(i > 0 && notBarr(mm[i-1][j]))
		GG(i-1, j);
	// Down
	if(i < m-1 && notBarr(mm[i+1][j]))
		GG(i+1, j);
}

int bfs(int m, int n)
{
	int step = 0;
	que.push(make_pair(sp[0], sp[1]));

	while(!que.empty())
	{
		go();
		que.pop();
	}

	if(mm[ep[0]][ep[1]] != 'B')
		step = mm[ep[0]][ep[1]] - '0';

	// clear
	nowStep = 0;
	touchEnd = false;

	return step;
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
					// Up
					if(i >= 2)
					{
						// up left
						if(j >= 1 && canPlace(mm[i-2][j-1]))
							mm[i-2][j-1] = 'x';
						// up right
						if(j <= n-2  && canPlace(mm[i-2][j+1]))
							mm[i-2][j+1] = 'x';
					}
					// Down
					if(i <= n-3)
					{
						// down left
						if(j >= 1 && canPlace(mm[i+2][j-1]))
							mm[i+2][j-1] = 'x';
						// down right
						if(j <= n-2 && canPlace(mm[i+2][j+1]))
							mm[i+2][j+1] = 'x';
					}
					// Left
					if(j >= 2)
					{
						// Left up
						if(i >= 1 && canPlace(mm[i-1][j-2]))
							mm[i-1][j-2] = 'x';
						// Left down
						if(i <= n-2 && canPlace(mm[i+1][j-2]))
							mm[i+1][j-2] = 'x';
					}
					// Right
					if(j <= n-3)
					{
						// Right up
						if(i >= 1 && canPlace(mm[i-1][j+2]))
							mm[i-1][j+2] = 'x';
						// Right down
						if(i <= n-2 && canPlace(mm[i+1][j+2]))
							mm[i+1][j+2] = 'x';
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

		#if 1
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
		// int step = bfs(m, n);

		// if(!step)
		// 	printf("King Peter, you can't go now!\n");
		// else
		// 	printf("Minimal possible length of a trip is %d\n", step);
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
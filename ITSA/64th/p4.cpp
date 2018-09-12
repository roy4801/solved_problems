#include <iostream>
#include <queue>

using namespace std;

#define LEFT_CHILD(x) (x * 2)
#define RIGHT_CHILD(x) (x * 2 + 1)
#define PARENT(x) (x / 2)

#define LEFT_CH_VAL(x) (p[x * 2])
#define RIGHT_CH_VAL(x) (p[x * 2 + 1])

int p[10000005];
int len = 0;
queue<int> que;

void readTree()
{
	int left, right, val, now = 1;

	scanf("%d %d %d", &val, &left, &right);

	p[now] = val;
	len++;

	if(left)
	{
		que.push(LEFT_CHILD(now));
	}

	if(right)
	{
		que.push(RIGHT_CHILD(now));
	}

	while(!que.empty())
	{
		int par = que.front();
		len++;
		que.pop();

		scanf("%d %d %d", &val, &left, &right);

		p[par] = val;

		if(left)
			que.push(LEFT_CHILD(par));
		if(right)
			que.push(RIGHT_CHILD(par));
	}
}

void dfs(int parentIdx)
{
	if(parentIdx == 1)
		printf("%d", p[parentIdx]);
	else
		printf(" %d", p[parentIdx]);

	if(LEFT_CH_VAL(parentIdx) != -1)
	{
		dfs(LEFT_CHILD(parentIdx));
	}
	
	if(RIGHT_CH_VAL(parentIdx) != -1)
	{
		dfs(RIGHT_CHILD(parentIdx));
	}
}

// int pw2(const int x)
// {
// 	if(x == 0)
// 		return 1;
// 	else if(x == 1)
// 		return 2;

// 	int p = pw2(x / 2);
// 	// if even
// 	if(x & 1)
// 	{
// 		return p * p * 2;
// 	}
// 	else
// 	{
// 		return p * p;
// 	}
// }
int main()
{
	#ifdef DBG
	freopen("p4.in", "r", stdin);
	freopen("p4.out", "w", stdout);
	#endif
	memset(p, -1, sizeof(p));
	readTree();

	// printf("%d %d\n", len, pw2(len));
	// putchar('\n');
	// for(int i = 1; i < pw2(len); i++)
	// {
	// 	printf("%d ", p[i]);
	// }
	dfs(1);
	putchar('\n');

	return 0;
}
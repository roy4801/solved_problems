/*
 * UVA 232 - Crossword Answers
 * author: roy4801
 * AC(C++) 0.0??
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "232"
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
#define N 10
int r, c;
char m[N+5][N+5]; // 1-index
int ord[N+5][N+5];
int kase = 1;
vector<pair<int, string>> v;

string cur;
int now;
bool stop, read;
inline void init()
{
	stop = false, read = false;
	now = 0;
	v.clear();
}
inline void st(int i, int j)
{
	// is read
	if(ord[i][j] > 0)
	{
		if(!read)
			now = ord[i][j];
		read = true;
	}
	// is wall && in reading
	else if(ord[i][j] == -1)
		if(read) stop = true;
	// In reading
	if(read && stop) // stop
	{
		v.emplace_back(now, cur);
		stop = read = false;
		cur = "";
		return;
	}
	if(read)
		cur += m[i][j];
}
inline void print()
{
	for(auto &i : v)
		printf("%3d.%s\n", i.F, i.S.c_str());
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(cin >> r && r)
	{
		cin >> c;
		memset(m, 0, sizeof(m));
		memset(ord, 0, sizeof(ord));

		for(int i = 1; i <= r; i++)
		{
			for(int j = 1; j <= c && cin >> m[i][j]; j++)
				if(m[i][j] == '*') ord[i][j] = -1;
			getchar();
		}
		// Process the ord[]
		int now = 1;
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				if((!m[i-1][j] || !m[i][j-1] // out of border
					|| ord[i-1][j] == -1 || ord[i][j-1] == -1) // wall
					&& ord[i][j] != -1) // current is not wall
					ord[i][j] = now++;
		// build the wall (outside c & r)
		for(int i = 1; i <= r; i++)
			ord[i][c+1] = -1;
		for(int j = 1; j <= c; j++)
			ord[r+1][j] = -1;

		if(kase > 1) puts("");
		printf("puzzle #%d:\n", kase++);

		puts("Across");
		init();
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c+1; j++)
				st(i, j);
		sort(v.begin(), v.end());
		print();

		puts("Down");
		init();
		for(int j = 1; j <= c; j++)
			for(int i = 1; i <= r+1; i++)
				st(i, j);
		sort(v.begin(), v.end());
		print();
	}
	return 0;
}
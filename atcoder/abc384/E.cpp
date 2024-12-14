#include <bits/stdc++.h>
using namespace std;

#define FR(x) do { if(!(x)) return 0; } while(0)
using ULL = unsigned long long;
using LL = long long;
using P = pair<int, int>;
#define X first
#define Y second
#define MP make_pair

int dir[][2] = {
	{-1, 0}, // up
	{ 0, 1}, // right
	{ 1, 0}, // down
	{ 0,-1}, // left
};
int h, w;
int x;
int p, q;
vector<vector<int>> S;

int str;
set<P> slime;

bool input()
{
	str = 0;
	slime.clear();
	
	FR(cin >> h >> w >> x);
	FR(cin >> p >> q);
	S.resize(h, vector<int>(w));
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			FR(cin >> S[i][j]);
	p--;
	q--;
	return 1;
}
	
bool ok(int i, int j)
{
	return 0 <= i && i < h && 0 <= j && j < w &&
			(S[i][j] < (str / 2.0));
}

void solve()
{
//	printf("> %d %d\n", p, q);
	str = S[p][q];
	slime.emplace(p, q);
	
	int loop = 0;
	while(1)
	{
	start:
		for(auto [p, q] : slime)
		{
			for(int i = 0; i < 4; i++)
			{
				int x = p+dir[i][0], y = q+dir[i][1];
				if(!slime.count(MP(x,y)) && ok(x, y))
				{
					str += S[x][y];
					slime.emplace(x, y);
//					printf("> %d %d\n", x, y);
					loop = 0;
					goto start;
				}
			}
		}
		
		loop++;
		if(loop >= 2)
		{
			break;
		}
	}
	
	cout << str << '\n';
}
	
int main()
{
	while(input())
	{
		solve();
	}
}
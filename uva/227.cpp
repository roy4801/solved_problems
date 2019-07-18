/*
 * UVA 227 - Puzzle
 * author: roy4801
 * AC(C++) 0.010
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "227"
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
char m[5][5];
string in;
int now;
bool fail;
int ni, nj;
int kase = 1;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	while(getline(cin, in))
	{
		if(now < 5)
		{
			if(in[0] == 'Z')
				break;
			for(int i = 0; i < 5; i++)
			{
				if(in[i] == ' ')
					ni = now, nj = i;
				m[now][i] = in[i];
			}
			now++;
		}
		else
		{
			for(int i = 0; i < in.size(); i++)
			{
				if(in[i] == '0')
				{
					if(kase != 1) puts("");
					printf("Puzzle #%d:\n", kase++);
					if(fail)
						puts("This puzzle has no final configuration.");
					else
						for(int a = 0; a < 5; a++)
							for(int b = 0; b < 5; b++)
								printf("%c%c", m[a][b], b==4?'\n':' ');

					fail = false;
					now = 0;
					break;
				}

				if(fail) continue;

				switch(in[i])
				{
					case 'A':
						if(ni - 1 >= 0)
						{
							swap(m[ni-1][nj], m[ni][nj]);
							ni--;
						}
						else
							fail = true;
					break;
					case 'B':
						if(ni + 1 <= 4)
						{
							swap(m[ni+1][nj], m[ni][nj]);
							ni++;
						}
						else
							fail = true;
					break;
					case 'R':
						if(nj + 1 <= 4)
						{
							swap(m[ni][nj+1], m[ni][nj]);
							nj++;
						}
						else
							fail = true;
					break;
					case 'L':
						if(nj - 1 >= 0)
						{
							swap(m[ni][nj-1], m[ni][nj]);
							nj--;
						}
						else
							fail = true;
					break;
					default:
						fail = true;
					break;
				}
			}
		}
	}

	return 0;
}
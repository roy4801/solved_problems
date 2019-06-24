/*
 * UVA 10033 - Interpreter
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10033"
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
int kase;
string in;
int prog, cur;
int reg[10], mem[1000];
int pc, inc;
int a, b;
bool halt, pt;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase;
	getchar();
	getchar();
	while(kase--)
	{
		memset(reg, 0, sizeof(reg));
		memset(mem, 0, sizeof(mem));
		pc = inc = prog = 0;
		halt = false;

		while(getline(cin, in) && in != "")
		{
			mem[prog++] = stol(in);
		}

		while(!halt)
		{
			cur = mem[pc];

			inc++;
			pc++;

			a = cur / 10 % 10;
			b = cur % 10;
			cur /= 100;
			
			switch(cur)
			{
				case 1:
					halt = true;
				break;
				// mov d, n
				case 2:
					reg[a] = b;
				break;
				// add d, n
				case 3:
					reg[a] += b;
					reg[a] %= 1000;
				break;
				// mul d, n
				case 4:
					reg[a] *= b;
					reg[a] %= 1000;
				break;
				// mov d, s
				case 5:
					reg[a] = reg[b];
				break;
				// add d, s
				case 6:
					reg[a] += reg[b];
					reg[a] %= 1000;
				break;
				// mul d, s
				case 7:
					reg[a] *= reg[b];
					reg[a] %= 1000;
				break;
				// mov d, [a]
				case 8:
					reg[a] = mem[reg[b]];
				break;
				// mov [a], s
				case 9:
				{
					mem[reg[b]] = reg[a];
				}
				break;
				// test s, s
				// jnz d
				case 0:
					if(reg[b] != 0)
						pc = reg[a];
				break;
			}
		}

		cout << (pt?"\n":"") << inc << '\n';
		pt = true;
	}

	return 0;
}

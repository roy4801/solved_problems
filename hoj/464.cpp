/*
 * HOJ 464 - 菇菇園
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "464"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define N 100
int kase;
int n, m, k; // mushroom, infected, distance
int x, y;
vector<PLL> inf, nor;
bool fl[N+5];
inline LL dis2(PLL a, PLL b)
{
	LL tmp = a.F-b.F, tmp2 = a.S-b.S;
	return tmp*tmp + tmp2*tmp2;
}
int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	USE_CPPIO();
	inf.reserve(2*N+5);
	nor.reserve(N+5);
	//
	cin >> kase;
	while(kase-- && cin >> n >> m >> k)
	{
		inf.clear();
		nor.clear();
		memset(fl, 0, sizeof(fl));
		k *= k;
		//
		for(int i = 0; i < n && cin >> x >> y; i++)
			if(i < m)
				inf.PB(MP(x, y));
			else
				nor.PB(MP(x, y));
		
		int i = 0;
		while(i < inf.size())
		{
			for(int j = 0; j < nor.size(); j++)
			{
				if(!fl[j])
				{
					if(dis2(inf[i], nor[j]) <= k)
					{
						inf.PB(nor[j]);
						fl[j] = true;
					}
				}
			}
			i++;
		}
		cout << inf.size() << '\n';
	}

	return 0;
}

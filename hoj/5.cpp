/*
 * HOJ 5 - 漢米頓的麻煩
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "5"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define INF 0x3f3f3f3f
#define N 100

int d[N][N]; // 0-index
int n;

void floyd_warshall()
{
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int in;
    while(cin >> n)
    {
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n && cin >> in; j++)
    			d[i][j] = in == 0 && i != j ? INF : in;

    	floyd_warshall();

    	int min_dis = INT_MAX;
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++)
    		{
    			if(i != j)
    			{
    				min_dis = min(min_dis, d[i][j] + d[j][i]);
    			}
    		}
    	cout << (min_dis >= INF ? -1 : min_dis) << '\n';
    }
	return 0;
}
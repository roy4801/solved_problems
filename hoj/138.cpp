/*
 * HOJ 138 - 海綿寶寶之我要吃美味蟹堡(最短路)
 * author: roy4801
 * AC(C++) 1.849
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "138"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

typedef pair<int, int> P;
#define N 50000
#define E 300000
#define INF 1e9
 
vector<P> w[E]; // (to, weight)
int d[N];       // 記錄起點到各個點的最短路徑長度
int parent[N];  // 記錄各個點在最短路徑樹上的父親是誰
bool visit[N];  // 記錄各個點是不是已在最短路徑樹之中
int n;
  
void dijkstra(int src)
{
    for (int i = 0; i < n; i++) visit[i] = false;   // initialize
    for (int i = 0; i < n; i++) d[i] = INF;
 
    d[src] = 0;
    parent[src] = src;
 
    // (dis, idx)
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.emplace(0, src);
 
    while(!pq.empty())
    {
        int a = -1, b = -1, wei;
 
        tie(wei, a) = pq.top();
        pq.pop();
 
        if(visit[a]) continue;
 
        d[a] = wei;
        visit[a] = true;
 
        for(auto i : w[a])
        {
            if(!visit[i.first])
                pq.emplace(wei + i.second, i.first);
        }
    }
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int edge; // node, number of edges
    int from, to, wei;
     
    while(cin >> n >> edge)
    {
        for(int i = 0; i < edge && cin >> from >> to >> wei; i++)
        {
            from--, to--;
            w[from].emplace_back(to, wei);
        }
        dijkstra(0); // 0 is src
 
        cout << (d[n-1] == INF ? -1: d[n-1]) << '\n';
    }

	return 0;
}
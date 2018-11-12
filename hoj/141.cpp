/*
 * HOJ 141 - 海綿寶寶之製作蟹堡(拓撲排序)
 * author: roy4801
 * AC(C++) 0.953
 */
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define PROB "141"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

#define INF 0x3f3f3f3f
typedef pair<int, int> P;
#define F first
#define S second

#define V 50000
#define E 200000
vector<int> e[V];
int conn[V]; // 一個點「被連」的數目
int n, m;    // 點 邊

vector<int> topo_sort()
{
    vector<int> res;
    for(int i = 0; i < n; i++) conn[i] = 0;
    // 紀錄每個點「被連」幾次
    for(int i = 0; i < n; i++)
        for(int j : e[i])
            conn[j]++;

    // 把所有被連數目為0加到q裡頭
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(conn[i] == 0)
            q.push(i);
    
    // 總共n次
    int i;
    for(i = 0; i < n; i++)
    {
        if(q.empty()) break;

        int f = q.front(); q.pop(); // 拿點

        res.push_back(f);
        conn[f] = -1; // 刪掉點f
        // 刪掉f這個點所連出去的邊
        for(int j : e[f])
        {
            conn[j]--;
            if(!conn[j]) // == 0
                q.push(j);
        }
        
    }
    return i==n ? res : vector<int>(1, -1);
}

int main()
{
	#ifdef DBG
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	int fr, to;
    while(cin >> n >> m)
    {
        for(int i = 0; i < m && cin >> fr >> to; i++)
            e[--fr].push_back(--to);

        auto topo = topo_sort();

        for(int i = 0; i < topo.size(); i++)
        {
            cout << (topo[i]!=-1 ? topo[i]+1 : -1) << '\n';
        }
    }

	return 0;
}

/*
 * UVA 10258 - Contest Scoreboard
 * author: roy4801
 * AC(C++) 0.000
 */
#include <bits/stdc++.h>

using namespace std;

#define PROB "10258"
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
#define BIT(x) (1<<(x))
#define N 100
struct Con
{
    int id, ac;
    bool sub;
    vector<int> time;
    Con() : time(10, 0) {}
    inline int getTotal() const
    {
        int acc = 0;
        for(int i = 1; i <= 9; i++)
            if(ac & BIT(i))
                acc += time[i];
        return acc;
    }
    inline int getAC() const
    {
    	int act = ac, acn = 0;
        for(; act; act >>= 1)
            if(act & 1)
                acn++;
        return acn;
    }
    void init(int id_)
    {
        id = id_;
        ac = 0;
        sub = false;
        for(int i = 0; i < 10; i++) time[i] = 0;
    }
    void print()
    {
        if(!sub) return;
        printf("%d %d %d\n", id, getAC(), getTotal());
    }
    friend bool operator<(const Con &lhs, const Con &rhs)
    {
        return lhs.getAC() != rhs.getAC()
            ? lhs.getAC() > rhs.getAC()
            : lhs.getTotal() != rhs.getTotal()
                ? lhs.getTotal() < rhs.getTotal()
                : lhs.id < rhs.id;
    }
}con[105];
void init()
{
    for(int i = 0; i <= N; i++)    con[i].init(i);
}
int kase;
int c, p, t; // contestant, problem, time
char res;
string s;
bool fl;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	cin >> kase; getchar(); getchar();
    while(kase--)
    {
        init();
        
        while(getline(cin, s) && s != "")
        {
            stringstream ss(s);
            ss >> c >> p >> t >> res;
            con[c].sub = true;
            if(res == 'C') // correct
            {
            	if(!(con[c].ac & BIT(p))) // not yet ac
	                con[c].time[p] += t;
	            con[c].ac |= BIT(p);
            }
            else if(res == 'I') // incorrect
            {
            	if(!(con[c].ac & BIT(p))) // not yet ac
                	con[c].time[p] += 20;
            }
        }
        
        sort(con+1, con+1+N);
        
        if(fl) puts("");
        fl = true;
        for(int i = 0; i <= N; i++)
            con[i].print();
    }
}
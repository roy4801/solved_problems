/*
 * UVA 484 - The Department of Redundancy Department
 * author: roy4801
 * AC(C++) 0.010
 */
#include <bits/stdc++.h>
using namespace std;

#define PROB "484"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int n;
map<int, int> m;
vector<int> ord;

int main()
{
    m.clear();
    ord.clear();
    while(cin >> n)
    {
        if(!m.count(n))
            ord.push_back(n);
        m[n]++;
    }
    for(int &i: ord)
    {
        cout << i << ' ' << m[i] << '\n';
    }
}

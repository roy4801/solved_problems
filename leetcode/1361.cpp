/*
 * Leetcode Medium 1361. Validate Binary Tree Nodes
 * author: roy4801
 * AC(C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define arr array
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution
{
public:
    int n;

    vector<int> p;
    void init(int n)
    {
        p.resize(n+5);
        for(int i = 0; i <= n; i++)
            p[i] = i;
    }
    int find(int x)
    {
        return x == p[x] ? x : (p[x]=find(p[x]));
    }
    void uni(int a, int b)
    {
        p[find(a)] = find(b);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& L, vector<int>& R)
    {
        // Check cycle
        init(n);
        for(int i = 0; i < n; i++)
        {
            int l = L[i], r = R[i];
            if(l != -1)
            {
                if(find(i) != find(l))
                    uni(i, l);
                else
                    return 0;
            }
            if(r != -1)
            {
                if(find(i) != find(r))
                    uni(i, r);
                else
                    return 0;
            }
        }

        // Every node has only one parent
        // And only one node has no parent
        vector<int> t((n+5)*2, 0);
        for(int i = 0; i < n; i++)
        {
            if(L[i] != -1)
                t[L[i]]++;
            if(R[i] != -1)
                t[R[i]]++;
        }
        int zero = 0;
        for(int i = 0; i < n; i++)
        {
            if(t[i] == 0)
                zero++;
            else if(t[i] != 1)
                return 0;
        }

        return zero == 1;
    }
};

int main()
{
    // skip
}

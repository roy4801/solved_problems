/*
 * Leetcode Hard 1569. Number of Ways to Reorder Array to Get Same BST
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

#define N 1000

class Solution {
public:
    // BST
    struct Node
    {
        int val;
        int cnt ;
        Node *l, *r;

        Node(int x) : val(x), l(0), r(0), cnt(0) {}
    };

    vector<int> v;
    int n;
    Node *r;
    int mod = 1e9+7;

    void insert(Node *prev, Node *cur, int lr, int x)
    {
        if(!cur)
        {
            if(lr == 1)
                prev->l = new Node(x);
            else if(lr == 2)
                prev->r = new Node(x);
            return;
        }

        if(x > cur->val)
            insert(cur, cur->r, 2, x);
        else
            insert(cur, cur->l, 1, x);
    }

    int buildCnt(Node *p)
    {
        if(!p->l && !p->r)
            return p->cnt = 1;

        int c = 1;
        c += p->l ? buildCnt(p->l) : 0;
        c += p->r ? buildCnt(p->r) : 0;
        p->cnt = c;
        return c;
    }
    
    int table[N+5][N+5];
    void build()
    {
        // build BST
        r = new Node(v[0]);
        for(int i = 1; i < n; i++)
            insert(0, r, 0, v[i]);
        // build num of node for each node on tree
        buildCnt(r);

        // build nCr table
        for(int i = 0; i <= 1000; i++)
        {
            table[i][0] = 1;
            table[i][i] = 1;
        }
        for(int i = 2; i <= 1000; i++)
        {
            for(int j = 1; j <= i-1; j++)
                table[i][j] = (table[i-1][j]%mod+table[i-1][j-1]%mod)%mod;
        }
    }

    int nCr(int n, int r)
    {
        return table[n][r];
    }
    int dfs(Node *p)
    {
        int l = p->l ? dfs(p->l) : 1;
        int r = p->r ? dfs(p->r) : 1;
        int ln = p->l ? p->l->cnt : 0;
        int rn = p->r ? p->r->cnt : 0;

        long long ans = 1;
        ans *= l % mod;
        ans %= mod;
        ans *= r % mod;
        ans %= mod;
        ans *= nCr(ln+rn, ln) % mod;
        ans %= mod;
        return ans;
        // return l * r * nCr(ln+rn, ln);
    }
    
    int numOfWays(vector<int>& nums)
    {
        v = nums;
        n = nums.size();

        build();
        return dfs(r)-1;
    }
};

/* DEBUG
void printGraph(Node *pre, Node *p)
{
    if(pre)
        printf("%d %d\n", pre->val, p->val);

    if(p->l)
        printGraph(pre, p->l);
    if(p->r)
        printGraph(pre, p->r);
}
void print(Node *p)
{
    printf("%d\n", p->cnt);
    if(p->l)
        print(p->l);
    if(p->r)
        print(p->r);
}
*/

int main()
{
    using InputType=vector<int>;
    vector<InputType> in = {
        {2,1,3},
        {3,4,5,1,2},
        {1,2,3},
        {4,2,1,3,5,6},
        {9,4,2,1,3,6,5,7,8,14,11,10,12,13,16,15,17,18},
    };
    for(auto &i : in)
        DBG(Solution{}.numOfWays(i));
}
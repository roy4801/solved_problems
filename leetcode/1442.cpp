/*
 * Leetcode Medium 1442. Count Triplets That Can Form Two Arrays of Equal XOR
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

// arr[i] ^ arr[i+1] ^ ... ^ arr[j-1] = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// 
// let
// a = arr[i] ^ arr[i+1] ^ ... ^ arr[j-1]
// b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// 
// Observe: a = b -> a ^ b = 0
// which means: arr[i] ^ arr[i+1] ^ ... ^ arr[j-1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
// So the problem becomes finding the interval [i, k] where its XOR equals 0

// straight forward
class Solution {
public:
    int countTriplets(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> pre(n+5); // pre[x] = xor(0, x)

        for(int i = 0; i < n; i++)
            pre[i] = (i >= 1 ? pre[i-1] : 0) ^ arr[i];
        auto Xor = [&](int a, int b)
        {
            return pre[b] ^ (a >= 1 ? pre[a-1] : 0);
        };

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int k = i+1; k < n; k++)
            {
                if(Xor(i, k) == 0)
                {
                    for(int j = i+1; j <= k; j++)
                    {
                        if(Xor(i, j-1) == Xor(j, k))
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// For the interval arr[i] ^ arr[i+1] ^ ... ^ arr[j-1] = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
// it have (k-i) number of triplets so the third for loop can be omitted
class Solution2 {
public:
    int countTriplets(vector<int>& arr)
    {
        int n = arr.size();
        int pre[n+5]; // pre[x] = xor(0, x)
        memset(pre, 0, sizeof(pre));

        pre[0] = arr[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1] ^ arr[i];

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int k = i+1; k < n; k++)
            {
                int a = pre[k];
                int b = i-1 >= 0 ? pre[i-1] : 0;
                if(a == b)
                    ans += k - i;
            }
        }
        return ans;
    }
};

int main()
{
    // skip
}
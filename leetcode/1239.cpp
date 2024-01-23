/*
 * Leetcode Medium 1239. Maximum Length of a Concatenated String with Unique Characters
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

// 參考題解 1 寫出
class Solution {
public:
    inline bool check(const string& a, const string& b)
    {
        int cnt[26] = {0};
        for(char c : a) cnt[c-'a']++;
        for(char c : b) cnt[c-'a']++;
        for(int i = 0; i < 26; i++)
            if(cnt[i] >= 2)
                return 0;
        return 1;
    }
    int maxLength(vector<string>& arr)
    {
        vector<string> ok = {""};

        for(auto& s : arr)
        {
            int n = ok.size();
            for(int i = 0; i < n; i++)
            {
                if(check(s, ok[i]))
                {
                    ok.push_back(s+ok[i]);
                }
            }
        }

        int ans = INT_MIN;
        for(auto i : ok)
            ans = max(ans, (int)i.size());
        return ans;
    }
};

// O(2^n) 喇過
#define Pick(p, x) ((p) | (1<<(x)))
#define UnPick(p, x) ((p) & ~(1<<(x)))
#define IsPick(p, x) ((p) & (1<<(x)))
class Solution {
public:
    vector<unordered_set<char>> v;
    vector<int> len;
    int n;
    int ans;
    vector<int> memo;
    int calc(int pick)
    {
        // if(memo[pick] != -1)
        //     return memo[pick];
        unordered_set<char> cur;
        for(int i = 0; i < n; i++)
        {
            if(!IsPick(pick, i))
                continue;
                
            for(char c : v[i])
            {
                if(cur.count(c))
                {
                    return 0;
                }
            }
            cur.insert(v[i].begin(), v[i].end());
        }
        return /*memo[pick]=*/cur.size();
    }
    int maxLength(vector<string>& arr)
    {
        n = arr.size();
        ans = INT_MIN;
        len.resize(n);
        memo.resize(pow(2, n)+5, -1);

        for(int i = 0; i < n; i++)
        {
            unordered_set<char> s;
            for(int j = 0; j < arr[i].size(); j++)
            {
                if(s.count(arr[i][j]))
                {
                    goto GG;
                }
                s.insert(arr[i][j]);
            }
            v.push_back(s);
            GG:
        }
        n = v.size();

        int k = pow(2, n);
        for(int i = 1; i < k; i++)
        {
            bitset<16> b(i);
            ans = max(ans, calc(b.to_ulong()));
        }

        return ans == INT_MIN ? 0 : ans;
    }
};

int main()
{
    // skip
}
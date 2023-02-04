/*
 * Leetcode Medium 567. Permutation in String
 * author: roy4801
 * AC(C++) 0.195 7.2MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define X first
#define Y second

class Solution
{
public:
    bool check(int a[26], int b[26])
    {
        int cnt = 0;
        for(int i = 0; i < 26; i++)
        {
            if(a[i] == b[i]) cnt++;
        }
        return cnt == 26;
    }
    
    bool checkInclusion(string a, string b)
    {
        unordered_map<string, bool> m;
        int ad[26], bd[26];
        bool ok = false;
        
        memset(ad, 0, 26 * sizeof(int));
        memset(bd, 0, 26 * sizeof(int));
        
        for(int i = 0; i < a.size(); i++)
            ad[a[i]-'a']++;

        for(int i = 0; i < max((int)(b.size() - a.size() + 1), 0); i++)
        {
            for(int j = 0; j < a.size(); j++)
                bd[b[i+j] - 'a']++;
            
            if(check(ad, bd))
            {
                ok = true;
                break;
            }
            
            memset(bd, 0, 26 * sizeof(int));
        }
        
        return ok;
    }
};

class Solution2
{
public:
    int A[26], B[26];
    bool checkInclusion(string a, string b) {
        int n = a.size(), m = b.size();
        for(char c : a)
            A[c-'a']++;

        int len = m-n+1;
        for(int i = 0; i < len; i++)
        {
            memset(B, 0, sizeof(B));
            for(int j = 0; j < n; j++)
            {
                B[b[i+j]-'a']++;
            }
            if(equal(A, A+26, B))
                return true;
        }
        return false;
    }
};

class Solution3 {
public:
    int A[26], B[26];
    bool checkInclusion(string a, string b) {
        int n = a.size(), m = b.size();
        if(n > m) return false;
        for(int i = 0; i < n; i++)
        {
            A[a[i]-'a']++;
            B[b[i]-'a']++;
        }

        for(int i = 0; i < m - n; i++)
        {
            if(equal(A, A+26, B))
                return true;

            B[b[n+i] - 'a']++;
            B[b[i] - 'a']--;
        }

        return equal(A, A+26, B);
    }
};

class Solution4 {
public:
    int A[26], B[26];
    bool checkInclusion(string a, string b) {
        int n = a.size(), m = b.size();
        if(n > m) return false;
        for(int i = 0; i < n; i++)
        {
            A[a[i]-'a']++;
            B[b[i]-'a']++;
        }

        // 計算 a 和 b 在 [0,n) 有幾種字元個數相同
        int cnt = 0;
        for(int i = 0; i < 26; i++)
            if(A[i] == B[i])
                cnt++;

        // 往右滑動窗口
        for(int i = 0; i < m - n; i++)
        {
            if(cnt == 26)
                return true;

            int l = b[i]-'a', r = b[n+i]-'a'; // left char to idx, right char to idx

            // 字串b 增加 r 字元 (右界往右移動一格)
            B[r]++;
            // 如果加入 r 之後，"字串b中 r 的個數"等於"字串a中 r 的個數"，則代表相等的數量增加 1，因為多了一種相等的字元種類 (r)
            if(B[r] == A[r])
                cnt++;
            // 如果加入 r 之後比原來 (A[r]) 的多 1 ，則代表相等的數量減去 1，因為兩個字串 r 的各數不一樣
            else if(B[r] == A[r] + 1)
                cnt--;

            // 字串b 刪除 l 字元 (左界往右移動一格)
            B[l]--;
            // 如果移除 l 之後，"字串b中 l 的個數"等於"字串a中 l 的個數"，則代表相等的數量增加 1，因為多了一種相等的字元種類 (l)
            if(B[l] == A[l])
                cnt++;
            // 如果移除 l 之後比原來 (A[l]) 的少 1 ，則代表相等的數量減去 1，因為兩個字串 l 的各數不一樣                
            else if(B[l] == A[l] - 1)
                cnt--;
        }

        return cnt == 26;
    }
};

int main()
{
    // cout << Solution3{}.checkInclusion("ab", "eidbaooo") << '\n';
    vector<pair<string,string>> in = {
        {"ab", "eidbaooo"},
        {"ab", "b"},
    };
    for(auto &i : in)
    {
        DBG(Solution4{}.checkInclusion(i.X, i.Y));
    }
}
/*
 * Leetcode Easy 1002. Find Common Characters
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

class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        int n = words.size();
        set<pair<char,int>> m[n];
        
        for(int i = 0; i < n; i++)
        {
            int ch[26] = {0};
            for(int j = 0; j < words[i].size(); j++)
            {
                char c = words[i][j];
                ch[c-'a']++;
                m[i].emplace(c, ch[c-'a']);
            }
        }

        vector<string> ans;
        for(auto it : m[0])
        {
            int cnt = 0;
            for(int i = 1; i < n; i++)
                if(m[i].count(it))
                    cnt++;
            if(cnt == n-1)
                ans.push_back(string{it.first});
        }
        return ans;
    }
};

// 觀察: 找每個字元最小的出現次數，即是該字元在答案陣列出現的次數
class Solution2 {
public:
    vector<string> commonChars(vector<string>& words)
    {
        int n = words.size();
        array<int, 26> cnt;
        cnt.fill(INT_MAX);
        
        for(int i = 0; i < n; i++)
        {
            int ch[26] = {0};
            for(int j = 0; j < words[i].size(); j++)
            {
                char c = words[i][j];
                ch[c-'a']++;   
            }

            for(int j = 0; j < 26; j++)
                cnt[j] = min(cnt[j], ch[j]);
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++)
            while(cnt[i]--)
            {
                char c = 'a'+i;
                ans.push_back(string{c});
            }
        return ans;
    }
};

int main()
{
    // skip
}
/*
 * Leetcode Medium 3081. Replace Question Marks in String to Minimize Its Value
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

using P=pair<int,char>; // exist count, char
#define X first
#define Y second
class Solution {
public:
    string minimizeStringValue(string s)
    {
        int n = s.size();
        vector<int> ch(26); // [ch-'a'] = count
        vector<char> q;
        
        for(int i = 0; i < n; i++)
            if(s[i] != '?')
                ch[s[i]-'a']++;
        
        priority_queue<P,vector<P>,greater<>> pq; // min-heap
        for(int i = 0; i < 26; i++)
            pq.emplace(ch[i], 'a'+i);
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '?')
            {
                auto k = pq.top();
                pq.pop();
                
                // s[i] = k.Y;
                q.push_back(k.Y);
                pq.emplace(k.X+1, k.Y);
            }
        }
        
        sort(q.begin(), q.end());
        int k = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == '?')
                s[i] = q[k++];
        
        return s;
    }
};

/*
"eq?umjlasi"
"abcdefghijklmnopqrstuvwxy??"
"abcdefghijklmnopqrstuvwxy?"
*/

int main()
{
    // skip
}
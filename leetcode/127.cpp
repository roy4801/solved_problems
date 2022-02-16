/*
 * Leetcode Hard 127. Word Ladder
 * author: roy4801
 * AC(C++) 184ms 39.5MB
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

#define N 5000

class Solution {
public:
    /* Graph */
    vector<int> G[N+5][10]; // [from][path] -> to

    /* string to index converter */
    unordered_map<string, int> s2i; // s2i["dog"] = 2

    /* Original string list */
    vector<string> v;
    
    /* word size */
    int siz;

    void build(string fr)
    {
        /* 可以走的路徑對到走到的可能 */
        unordered_map<string, vector<string>> m; // m[".og"] = {"dog", "log", "cog"}
        
        // build m and s2i
        int a = 0;
        for(string s : v)
        {
            s2i[s] = a++;
            // Dig a hole
            for(int i = 0; i < s.size(); i++)
            {
                string orig = s;
                s[i] = '.';
                m[s].push_back(orig);
                s = orig;
            }
        }

        siz = v[0].size();

        // build G[][]
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v[i].size(); j++)
            {
                string orig = v[i];
                char c = v[i][j];
                //
                v[i][j] = '.';

                if(m.count(v[i]))
                {
                    for(string k : m[v[i]])
                    {
                        if(orig == k)
                            continue;
                        // printf("%s %s i=%d j=%d k=%d\n", v[i].c_str(), k.c_str(), i, j);
                        G[i][j].push_back(s2i[k]);
                    }
                }

                v[i][j] = c;
            }
        }

        // build fr
        v.push_back(fr);
        s2i[fr] = v.size()-1;
        for(int i = 0; i < fr.size(); i++)
        {
            string orig = fr;
            fr[i] = '.';

            if(m.count(fr))
            {
                for(string k : m[fr])
                {
                    if(orig == k)
                        continue;
                    
                    G[s2i[orig]][i].push_back(s2i[k]);
                }
            }

            fr = orig;
        }
    }

    // TLE QAQ
    int ans = INT_MAX;
    void dfs(int step, int a, int b)
    {
        // printf("cur = %d step = %d\n", a, step);
        
        if(a == b)
        {
            // printf("WOW\n");
            // printf("cur = %d step = %d\n", a, step);
            ans = min(ans, step);
            return;
        }

        for(int i = 0; i < siz; i++)
        {
            for(int j : G[a][i]) // from a pass i to j
            {
                if(!visit[j]) // not visit yet
                {
                    visit[a] = true;
                    dfs(step+1, j, b);
                    visit[a] = false;
                }
            }
        }
    }

    int val[N+5];    // Distance of node i
    bool visit[N+5]; // Is node i visited
    void bfs(int a, int b)
    {
        queue<int> q;
        q.push(a);
        val[a] = 0;

        memset(val, 0, sizeof(val));
        memset(visit, 0, sizeof(visit));

        while(!q.empty())
        {
            int cur = q.front(); q.pop();

            // cur -- i --> j
            for(int i = 0; i < siz; i++)
            {
                for(int j : G[cur][i])
                {
                    // If not visited
                    if(!visit[j])
                    {
                        q.push(j); // visit in the future
                        val[j] = val[cur] + 1; // move 1 step
                        visit[j] = true;
                    }
                }
            }
        }
    }

    int ladderLength(string fr, string to, vector<string>& l)
    {
        v = l;
        build(fr);

        if(!s2i.count(to))
            return 0;

        // memset(visit, 0, sizeof(visit));
        // dfs(0, s2i[fr], s2i[to]);
        // return ans!=INT_MAX ? ans+1 : 0;

        bfs(s2i[fr], s2i[to]);
        int ans = val[s2i[to]];
        
        return ans ? ans+1 : 0;

        // print graph
        // for(int i = 0; i < v.size(); i++)
        // {
        //     cout << i << "->" << v[i] << "\n";
        //     for(int j = 0; j < v[0].size(); j++)
        //     {
        //         cout << j << ' ';
        //         for(int k : G[i][j])
        //         {
        //             cout << v[k] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << "=================" << '\n';
        // }
    }
};

int main()
{
    vector<string> l = {"hot","dot","dog","lot","log","cog"};
    string start = "hit", end = "cog";
    
    // vector<string> l = {"hot","dot","dog","lot","log","cog"};
    // string start = "hit", end = "cog";

    // vector<string> l = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    // string start = "qa", end = "sq";

    cout << Solution{}.ladderLength(start, end, l) << '\n';
}
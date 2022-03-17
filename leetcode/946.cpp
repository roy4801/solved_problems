/*
 * Leetcode Medium 946. Validate Stack Sequences
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int i = 0, j = 0;
        stack<int> s;
        
        while(i < pushed.size() || j < popped.size())
        {
            while(!s.empty() && j < popped.size() && s.top() == popped[j])
            {
                printf("Pop %d\n", popped[j]);
                s.pop();
                j++;
            }
            
            printf("i=%d j=%d\n", i, j);
            if(i < pushed.size())
            {
                printf("Push %d\n", pushed[i]);
                s.push(pushed[i++]);
            }
            else
            {
                if(j < popped.size() && s.top() != popped[j])
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<int> pu = {1,2,3,4,5};
    vector<int> po = {4,5,3,2,1};
    // vector<int> po = {4,3,5,1,2};

    cout << Solution{}.validateStackSequences(pu, po) << '\n';
}
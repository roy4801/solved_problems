/*
 * Leetcode Hard 1675. Minimize Deviation in Array
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

class Solution
{
public:
    int minimumDeviation(vector<int>& n)
    {
        priority_queue<int> pq;
        int minN = INT_MAX, dif = INT_MAX;

        for(int i : n)
        {
            if(i % 2 != 0)
                i *= 2;
            // printf("%d ", i);
            pq.push(i);
            minN = min(minN, i);
        }
        // puts("");



        while(!pq.empty())
        {
            // printf("top = %d\n", pq.top());
            if(pq.top() % 2 != 0)
            {
                dif = min(dif, pq.top() - minN);    
                break;
            }

            dif = min(dif, pq.top() - minN);
            minN = min(minN, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop(); // pop max
        }

        return dif;
    }
};

int main()
{
    // vector<int> v = {1,2,3,4};
    vector<int> v = {4,1,5,20,3};
    cout << Solution{}.minimumDeviation(v) << '\n';
}
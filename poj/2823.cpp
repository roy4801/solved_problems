/*
 * POJ 2823 - Sliding Window
 * author: roy4801
 * AC(C++)
 */
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define PROB "2823"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int n, k;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("./testdata/" PROB TESTC ".in", "r", stdin);
	freopen("./testdata/" PROB ".out", "w", stdout);
	#endif
	deque<int> deq;
    vector<int> in;
    int tmp;
    
    while(scanf("%d %d", &n, &k) != EOF)
    {
        for(int i = 0; i < n && scanf("%d", &tmp) != EOF; i++)
            in.push_back(tmp);
        
        // 找最小
        for(int i = 0; i < in.size(); i++)
        {
            // 超過三個，如果舊的還在deq裡頭，則要pop掉
            while(deq.size() && deq.front() <= i-k)
                deq.pop_front();
                
            // 等於也要算，因為要往後更新
            while(deq.size() && in[deq.back()] >= in[i])
                deq.pop_back();
            
            deq.push_back(i);
            
            if(i >= k-1)
                printf(i == k-1 ? "%d" : " %d", in[deq.front()]);
        }
        
        putchar('\n');
        deq.clear();
        
        // 找最大
        for(int i = 0; i < in.size(); i++)
        {
            while(deq.size() && deq.front() <= i - k)
                deq.pop_front();
                
            while(deq.size() && in[deq.back()] <= in[i])
                deq.pop_back();
            
            deq.push_back(i);
            
            if(i >= k-1)
                printf(i == k-1 ? "%d" : " %d", in[deq.front()]);
        }
    }

	return 0;
}

/*
 * Leetcode Medium 36. Valid Sudoku
 * author: roy4801
 * AC(C++)
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
    set<int> R[9], C[9], B[9];
    int b[9][9];
    bool isValidSudoku(vector<vector<char>>& in)
    {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                b[i][j] = (in[i][j] != '.') ? in[i][j] - '0' : 0;
        
        // row
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(R[i].count(b[i][j]))
                    return false;
                if(b[i][j])
                    R[i].insert(b[i][j]);
            }
            
        // col
        for(int j = 0; j < 9; j++)
            for(int i = 0; i < 9; i++)
            {
                if(C[j].count(b[i][j]))
                    return false;
                if(b[i][j])
                    C[j].insert(b[i][j]);
            }
        
        // box
        int idx = 0;
        for(int c = 0; c < 9; c += 3)
        {
            for(int d = 0; d < 9; d += 3)
            {
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        if(B[idx].count(b[c+i][d+j]))
                            return false;
                        if(b[c+i][d+j])
                            B[idx].insert(b[c+i][d+j]);
                    }
                }
                idx++;
            }
        }
        
        return true;
    }
};

int main()
{
    // skip
}
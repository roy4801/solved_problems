/*
 * Leetcode Hard 68. Text Justification
 * author: roy4801
 * (C++)
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
    vector<string> fullJustify(vector<string>& words, int mw)
    {
        vector<string> ans;
        int n = words.size();
        int word = 0; // num of words picked
        int num = 0;  // char count for picked words
        vector<string> pk; // picked words
        string line;  // this line

        int i = 0;
        while(i < n)
        {
            // increment char count first for judgement
            num += words[i].size();
            // char_count  > maxWidth - min_space_count
            // if pick words[i] will exceeds the limit
            if(num >= mw - (word-1))
            {
                num -= words[i].size();

                int space = mw - num;
                int intvl = word-1 == 0 ? 1 : word-1;
                int spw = space / intvl; // space per word
                int ext = space % intvl; // remaining spaces
                // form a line
                for(int j = 0; j < word; j++)
                {
                    line += pk[j];

                    if(word != 1 && j == word-1)
                        continue;

                    for(int k = 0; k < spw; k++)
                        line += ' ';
                    // remaining spaces need to spread evenly
                    if(ext)
                    {
                        line += ' ';
                        ext--;
                    }
                }

                ans.push_back(line);
                line = "";
                pk.clear();
                word = num = 0;
                continue;
            }

            // picked one word
            pk.push_back(words[i]);
            word++;
            i++;
        }
        
        // last line
        for(int i = 0; i < word; i++)
        {
            line += pk[i];

            if(i == word-1)
                continue;
            
            line += ' ';
        }
        // remaining spaces for the last line
        int space = mw-line.size();
        for(int i = 0; i < space; i++)
            line += ' ';

        ans.push_back(line);
        return ans;
    }
};

/*
["This", "is", "an", "example", "of", "text", "justification."]
16
["What","must","be","acknowledgment","shall","be"]
16
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
20
["My","momma","always","said,","Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."]
20
*/

int main()
{
    // skip
}
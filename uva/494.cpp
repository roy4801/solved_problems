/*
 * Uva 494 - Kindergarten Counting Game
 * author: roy4801
 * AC(C++)
 */
#include <iostream>
//#include <ctype.h>

using namespace std;

int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("494.in", "r", stdin);
    freopen("494.out", "w", stdout);
    #endif
    char input[10000];
    
    while(cin.getline(input, 10000))
    {
        int word = 0, length = 0;
        char *ch = input;
        bool isAlpha = false;
        
        while(*ch)
        {
            length++;
            ch++;
        }
        
        for(int i = 0; i < length + 1; i++)
        {
            if(isalpha(input[i]))
            {
                isAlpha = true;
            }
            else
            {
                if(isAlpha)
                {
                    word++;
                }
                
                isAlpha = false;
            }
        }
        
        cout << word << endl;
    }
    
    return 0;
}
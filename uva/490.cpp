#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("490.in", "r", stdin);
    freopen("490.out", "w", stdout);
    #endif
    
    char line[100][101] = {0};
    int now = 0;
    int index = 0;
    
    // Get input
    while(cin.getline(line[now], 101))
    {
        if(!cin.eof())
        {
            now++;
        }
    }

    // Find the maximum
    int max_length = 0;
    for(int i = 0; i < now; i++)
    {
        if(i == 0)
        {
            max_length = strlen(line[i]);
        }
        else if(max_length < strlen(line[i]))// i != 0
        {
            max_length = strlen(line[i]);
        }
//        cout << strlen(line[i]) << endl; 
    }
    
    // 
    for(int i = 0; i < max_length; i++)
    {
        for(int j = now - 1; j >= 0; j--)
        {
            if(line[j][i] == 0)
            {
                putchar(' ');
            }
            else
            {
                printf("%c", line[j][i]);
            }
        }
        putchar('\n');
    }
    
    return 0;
}
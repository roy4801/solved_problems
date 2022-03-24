#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int kase, x, y;
    cin >> kase;
    while(kase-- && cin >> x >> y)
    {
        int a = x*x + y*y;
        int b = sqrt(a);
        
        if(x == 0 && y == 0)
        {
            puts("0");
            continue;
        }
        if(b*b == a)
            puts("1");
        else
            puts("2");
    }
}
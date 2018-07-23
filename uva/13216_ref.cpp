/* 
 * Ref: https://github.com/morris821028/UVa/blob/master/volume132/13216%20-%20Problem%20with%20a%20ridiculously%20long%20name%20but%20with%20a%20ridiculously%20short%20description.cpp 
 */
#include <bits/stdc++.h>
using namespace std;

int f[1024] = {1}, tail = 0, cycle = 1;

void build() {
    int c[128] = {};
    int x = 1;

    for (int i = 1; ; i++)
    {
        x = (x*66) % 100;
        f[i] = x;

        if (c[x])
        {
            tail = c[x]-1;
            cycle = i - c[x];
            break;
        }
        c[x] = i;
    }
}

int main() {
    freopen("testdata/13216.out", "w", stdout);
    build();

    int testcase;
    char s[1024];

    scanf("%d", &testcase);

    while (testcase--)
    {
        scanf("%s", s);

        int n = strlen(s);
        if (n < 2)
        {
            int x;
            
            sscanf(s, "%d", &x);

            if (x <= 1)
                printf("%d\n", f[x]);
            else
                printf("%d\n", f[(x-2)%5+2]);
            
            continue;
        }
        
        int t = (s[n-1]-'0'+3)%5;
        printf("%d\n", f[t+2]);
    }
    return 0;
}
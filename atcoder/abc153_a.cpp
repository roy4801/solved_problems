#include <bits/stdc++.h>
using namespace std;
int h, a;
int main(int argc, char *argv[])
{
    while(cin >> h >> a)
    {
        printf("%d\n", (int)ceil((double)h / a));
    }
}
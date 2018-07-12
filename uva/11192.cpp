/*
 * Uva 11192 - Group Reverse
 * author: roy4801
 * AC(C++) 0.000
 */
#include <iostream>
#include <cstring>
// #include <algorithm>

using namespace std;

// My practice of implment reverse()
// Of course, it's slower than std::reverse() a little bit :(
void myreverse(char *s, char *endp)
{
    int length = 0;
    char *c = s;

    // Counting the lenght of [s, endp)
    while(c != endp)
    {
        c++;
        length++;
    }
    endp--;

    for(int a = 0; a < length / 2; a++)
    {
        // swap
        char tmp = s[a];
        s[a] = endp[-a];
        endp[-a] = tmp;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("./testdata/11192.in", "r", stdin);
    freopen("./testdata/11192.out", "w", stdout);
    #endif
    int group;
    char s[101];

    while(scanf("%d", &group) != EOF && group 
        && scanf("%s", s) != EOF)
    {
        int n = strlen(s) / group;

        for(int i = 0; i < group; i++)
            myreverse(s + i * n, s + (i + 1) * n);

        printf("%s\n", s);
    }

    return 0;
}
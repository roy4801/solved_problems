#include <bits/stdc++.h>
using namespace std;

string s;
int cur = 0;

char read()
{
    return s[cur++];
}
char peek()
{
    return s[cur+1];
}
bool isEnd()
{
    return cur >= s.size();
}

int nxt[300];
#define NUMBER1 256
#define NUMBER2 257
#define END     258

void init()
{
    nxt['m'] = 'u';
    nxt['u'] = 'l';
    nxt['l'] = '(';
    nxt['('] = NUMBER1;
    nxt[NUMBER1] = ',';
    nxt[','] = NUMBER2;
    nxt[NUMBER2] = ')';
    nxt[')'] = END;
}

int stat = -1;
int num1, num2;
int ans = 0;
void state(char c)
{
    if(stat == -1 && c == 'm')
    {
        cout << "> init" << '\n';
        stat = 'm';
        return;
    }
    
    if(stat == '(' || stat == ',')
    {
        if(isdigit(c))
        {
            stat = nxt[stat];
        }
        else
        {
            stat = -1;
        }
        return;
    }

    if(stat == NUMBER1 || stat == NUMBER2)
    {
        cout << "IN" << '\n';
        if(isdigit(c))
        {
            cout << "> match " << c << '\n';
            int* num;
            if(stat == NUMBER1) num = &num1;
            else if(stat == NUMBER2) num = &num2;
            *num *= 10;
            *num += c - 'a';
            
        }
        else if(nxt[stat] == nxt[NUMBER1] || nxt[stat] == nxt[NUMBER2])
        {
            stat = nxt[stat];
        }
        else
        {
            stat = -1;
        }
        return;
    }

    if(nxt[stat] == END)
    {
        printf("> END %d %d\n", num1, num2);
        ans += num1 * num2;
        stat = -1;
        return;
    }

    if(nxt[stat] == c)
    {
        stat = nxt[stat];
        cout << "> match " << c << ' ';
        cout << "expect next " << nxt[stat] << '\n';
    }
    else
    {
        stat = -1;
    }
}

char buf[10];
const char* getStatStr(int stat)
{
    switch(stat)
    {
    case -1:
        return "None";
    case NUMBER1:
        return "NUM1";
    case NUMBER2:
        return "NUM2";
    case END:
        return "END";
    default:
        buf[0] = stat;
        buf[1] = '\0';
        return buf;
    }
}
int main()
{
    init();

    char c;
    while(cin >> c)
        s += c;
    
    while(!isEnd())
    {
        c = read();
        printf("stat %s, Read %c\n", getStatStr(stat), c);
        state(c);
    }

    cout << ans << '\n';
}

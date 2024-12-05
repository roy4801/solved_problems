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
    return s[cur];
}
bool isEnd()
{
    return cur >= s.size();
}


int stat = 0; // 0 = letter, 1 = number

int *num;
int num1, num2;
int ans = 0;
int op = 0;
void state(char c, char nc)
{
    printf("> op=%d c=%c nc=%c ", op, c, nc);
    
    if((op == 1 && c == 'u'   && nc == 'l'   ) ||
       (op == 2 && c == 'l'   && nc == '('   ) ||
       (op == 3 && c == '('   && isdigit(nc) ) || 
       (op == 4 && isdigit(c) && isdigit(nc) ) ||
       (op == 4 && isdigit(c) && nc == ','   ) ||
       (op == 6 && c == ','   && isdigit(nc) ) ||
       (op == 7 && isdigit(c) && nc == ')'   ) ||
       (op == 8 && c == ')'                  ) )
    {
        printf(" IN\n");
        if(c == '(')
        {
            printf("> start num1\n");
            num = &num1;
            num1 = 0;
        }
        else if(c == ',')
        {
            printf("> start num2\n");
            num = &num2;
            num2 = 0;
        }
        else if(c == ')')
        {
            printf("> %d %d\n", num1, num2);
            ans += num1 * num2;
            num1 = num2 = 0;
            op = 0;
        }
        else if(isdigit(c))
        {
            printf("> record %d\n", c - '0');
            *num *= 10;
            *num += c - '0';
        }
    }
    else
    {
        printf("NOT IN\n");
        num = nullptr;
        num1 = num2 = 0;
    }
    
    if(c == 'm'   && nc == 'u'   ) op = 1;
    if(c == 'u'   && nc == 'l'   ) op = 2;
    if(c == 'l'   && nc == '('   ) op = 3;
    if(c == '('   && isdigit(nc) ) op = 4;
    if(isdigit(c) && isdigit(nc) ) op = 5;
    if(isdigit(c) && nc == ','   ) op = 6;
    if(c == ','   && isdigit(nc) ) op = 7;
    if(isdigit(c) && nc == ')'   ) op = 8;
}

int main()
{
     setvbuf(stdout, NULL, _IONBF, 0);
    
    char c;
    while(cin >> c)
        s += c;
    
    while(!isEnd())
    {
        c = read();
        state(c, peek());
    }

    cout << ans << '\n';
}

/*
xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
*/
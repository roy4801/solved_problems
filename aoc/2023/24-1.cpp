/*
 * Acvent of Code Day 24: Never Tell Me The Odds
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "..\helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define arr array
#define PB push_back
#define MP make_pair
#define X first
#define Y second

#define LOW 2e14
#define HIGH 4e14

using LD=long double;

struct Point
{
    LD x, y;

    bool ok()
    {
        return isnormal(x) && isnormal(y) &&
               LOW <= x && x <= HIGH &&
               LOW <= y && y <= HIGH;
    }
};

struct Line
{
    Line(LD x, LD y, LD u, LD v)
        : x(x), y(y), u(u), v(v)
    {
    }
    Line(Point pos, Point dir)
        : x(pos.x), y(pos.y), u(dir.x), v(dir.y)
    {
    }

    Point intersect(const Line& rhs)
    {
        LD x0 = x, y0 = y;
        LD a0 = v/u;
        LD b0 = y0 - a0 * x0;
        // printf("a=%.2Lf b=%.2Lf\n", a0, b0);

        LD x1 = rhs.x, y1 = rhs.y;
        LD a1 = rhs.v/rhs.u;
        LD b1 = y1 - a1 * x1;
        // printf("a=%.2Lf b=%.2Lf\n", a1, b1);

        LD x = (b1 - b0) / (a0 - a1);
        LD y = a0 * x + b0;
        return {x, y};
    }

    LD x, y;
    LD u, v;
};

vector<Line> lines;
int n;

void solve()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            auto& a = lines[i], &b = lines[j];
            auto p = a.intersect(b);
            // printf("%.2Lf %.2Lf %s %.2Lf %.2Lf ", a.x, a.y, p.ok()?"V":"X", b.x, b.y);
            // printf("(%.2Lf %.2Lf)", p.x, p.y);
            if(p.ok())
            {
                LD t0x = (p.x - a.x) / a.u;
                // LD t0y = (p.y - a.y) / a.v;
                LD t1x = (p.x - b.x) / b.u;
                // LD t1y = (p.y - b.y) / b.v;
                // printf(" %.2Lf %.2Lf %.2Lf %.2Lf ", t0x, t0y, t1x, t1y);
                if(t0x > 0 && t1x > 0)
                    cnt++;
            }
            // puts("");
        }
    }
    printf("ans = %d\n", cnt);
}

int main()
{
    freopen("24.in", "r", stdin);

    string s;
    while(getline(cin, s))
    {
        LD x, y, z, a, b, c;
        sscanf(s.c_str(), "%Lf, %Lf, %Lf @ %Lf, %Lf, %Lf\n", &x, &y, &z, &a, &b, &c);
        // printf("%lf %lf %lf\n%lf %lf %lf\n", x, y, z, a, b, c);
        lines.emplace_back(x, y, a, b);
    }
    n = lines.size();

    solve();
}

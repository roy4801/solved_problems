#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;
using P = pair<int,int>;
#define X first
#define Y second

struct Point
{
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
    Point(const Point& other) : Point(other.x, other.y) {}

    friend Point operator+(const Point& lhs, const Point& rhs) { Point result(lhs); result += rhs; return result; }
    friend Point operator-(const Point& lhs, const Point& rhs) { Point result(lhs); result -= rhs; return result; }
    Point& operator+=(const Point& other) { x += other.x; y += other.y; return *this; }
    Point& operator-=(const Point& other) { x -= other.x; y -= other.y; return *this; }
    Point& operator*=(const int mul) { x *= mul; y *= mul; return *this; }
    bool operator<(const Point& other) const { return make_pair(x, y) < make_pair(other.x, other.y); }
    bool operator==(const Point& other) const { return make_pair(x, y) == make_pair(other.x, other.y); }
};

int n, m;
vector<string> M;
map<char, vector<Point>> pos; // freq -> (x, y), ...

void solve()
{
    set<Point> anti;

    for(auto&& [ch, p] : pos)
    {
        int k = p.size();
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(i == j)
                    continue;

                auto p_ji = p[j] - p[i];
                p_ji *= 2;
                auto an = p[i] + p_ji;
                // cout << ">> " << an.x << ' ' << an.y << '\n';
                if(an.x >= 0 && an.x < n && an.y >= 0 && an.y < m)
                {
                    anti.insert(an);
                }
            }
        }
    }

    cout << anti.size() << '\n';

    auto tmp = M;
    for(auto& i : anti)
    {
        tmp[i.x][i.y] = '#';
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            printf("%c%c", tmp[i][j], j==m-1 ? '\n' : ' ');
}

void debug_pos()
{
    for(auto&& [ch, p] : pos)
    {
        printf("%c: ", ch);
        for(auto&& i : p)
        {
            printf("(%d, %d) ", i.x, i.y);
        }
        cout << '\n';
    }
}

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    string s;
    while(cin >> s)
    {
        M.push_back(s);
    }

    n = M.size();
    m = M[0].size();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(M[i][j] != '.')
                pos[M[i][j]].emplace_back(i, j);
        }

    debug_pos();

    solve();
} 
#include <bits/stdc++.h>

template<typename T>
void print(const char *name, const std::vector<T> &v)
{
    cout << name << " = [";
    for(int i = 0; i < v.size(); i++)
        cout << (i > 0 ? ", " : "") << v[i];
    cout << "]\n";
}

template<typename T1, typename T2>
void print(const char *name, const std::map<T1, T2> &m)
{
    cout << name << " = {\n";
    int n = 0;
    for(auto && [k, v] : m)
    {
        cout << "  ";
        cout << k << ": " << v << (n==m.size()-1 ? "" : ",") << '\n';
        n++;
    }
    cout << "}\n";
}

#define DBG(x) print(#x, (x))
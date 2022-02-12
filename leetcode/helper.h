#pragma once
#ifndef _HELPER_H_
#define _HELPER_H_

#include <bits/stdc++.h>

template<typename T>
std::string plain_print(const T &v)
{
    return std::to_string(v);
}

template<>
std::string plain_print(const std::string &v)
{
    return "\"" + v + "\"";
}

template<typename T>
std::string plain_print(const std::vector<T> &v)
{
    std::string res = "[ ";
    int cnt = 0;

    for(auto &i : v)
    {
        cnt++;
        res += plain_print(i) + (cnt != v.size() ? ", " : "");
    }

    res += " ]";
    return res;
}

template<typename T1, typename T2>
std::string plain_print(const std::map<T1, T2> &m)
{
    std::string res = "{\n";
    int n = 0;
    for(auto && [k, v] : m)
        res +=  "  " + plain_print(k) + " -> " + plain_print(v) + (n++==m.size()-1 ? "" : ",") + '\n';
    res += "}\n";

    return res;
}

template<typename T1, typename T2>
std::string plain_print(const std::unordered_map<T1, T2> &m)
{
    std::string res = "{\n";
    int n = 0;

    std::map<T1, T2> tmp;
    for(auto && [k, v] : m)
        tmp[k] = v;

    for(auto && [k, v] : tmp)
        res +=  "  " + plain_print(k) + " -> " + plain_print(v) + (n++==m.size()-1 ? "" : ",") + '\n';
    res += "}\n";

    return res;
}

template<typename T>
std::string plain_print(const std::set<T> &v)
{
    std::string res = "{";
    int cnt = 0;

    for(auto & i : v)
        res += (cnt++ > 0 ? ", " : "") + plain_print(i);
    res += "}\n";

    return res;
}

template<typename T>
void print(const char *name, const T &v)
{
    cout << name << " = " << plain_print(v) << '\n';
}

#define DBG(x) print(#x, (x))

#endif
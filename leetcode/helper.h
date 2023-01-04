#pragma once
#ifndef _HELPER_H_
#define _HELPER_H_

#include <bits/stdc++.h>

#ifndef LEETCODE_NO_HELPER
#include "leetcode_helper.h"
#endif

template<typename T1, typename T2>
std::string plain_print(const std::pair<T1, T2> &p);

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

using ListNodePtr = ListNode*;
template<>
std::string plain_print(const ListNodePtr &v)
{
    std::string res = "{";
    ListNodePtr cur = v;
    while(cur)
    {
        res += std::to_string(cur->val);
        cur = cur->next;
        if(cur) res += " -> ";
    }
    res += "}\n";

    return res;
}

using TreeNodePtr = TreeNode*;
template<>
std::string plain_print(const TreeNodePtr &r)
{
    std::string buf;
    // Ref: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
    std::function<void(const std::string &, TreeNode *, bool)> print_impl =
        [&print_impl, &buf](const std::string &prefix, TreeNode *r, bool left) {
            if(!r) return;
            buf += prefix;
            buf += (left ? "+--" : "|--" );
            buf += plain_print(r->val) + "\n";
            print_impl(prefix + (left ? "|   " : "    "), r->left, true);
            print_impl(prefix + (left ? "|   " : "    "), r->right, false);
        };
    print_impl("", r, false);
    return buf;
}

template<typename T>
std::string plain_print(const std::vector<T> &v)
{
    std::string res = "[ ";
    typename std::vector<T>::size_type cnt = 0;

    for(auto &i : v)
    {
        cnt++;
        res += plain_print(i) + (cnt != v.size() ? ", " : "");
    }

    res += " ]";
    return res;
}

template<typename T>
std::string plain_print(const std::stack<T> &s)
{
    std::stack<T> tmp = s;
    std::vector<T> ans;
    while(!tmp.empty())
    {
        ans.push_back(tmp.top());
        tmp.pop();
    }
    reverse(ans.begin(), ans.end());
    return plain_print(ans);
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
std::string plain_print(const std::multimap<T1, T2> &m)
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
    std::map<T1, T2> tmp;
    for(auto && [k, v] : m)
        tmp[k] = v;

    return plain_print(tmp);
}

template<typename T1, typename T2>
std::string plain_print(const std::unordered_multimap<T1, T2> &m)
{
    std::multimap<T1, T2> tmp;
    for(auto && [k, v] : m)
        tmp.insert(std::make_pair(k, v));

    return plain_print(tmp);
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

template<typename T1, typename T2>
std::string plain_print(const std::pair<T1, T2> &p)
{
    std::string res = "p(";
    res += plain_print(p.first) + ", ";
    res += plain_print(p.second);
    res += ")\n";

    return res;
}

template<typename T>
void print(const char *name, const T &v)
{
    cout << name << " = " << plain_print(v) << '\n';
}

template<>
void print(const char *name, const TreeNodePtr &r)
{
    cout << name << ": " << '\n';
    cout << plain_print(r);
}

#define DBG(x) print(#x, (x))

#endif
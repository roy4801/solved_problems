template<typename T1, typename T2>
std::ostream& operator<<(std::ostream &out, const std::pair<T1, T2> &p)
{
    out << '(' << p.first << ',' << p.second << ')';
    return out;
}

// Vector
template<typename T>
std::string dbg(std::vector<T> v)
{
    std::stringstream ss;
    if(v.empty())
    {
        ss << "EMPTY";
        return ss.str();
    }
    for(auto i: v)
        ss << i << (i==v.back()?"":", ");
    return ss.str();
}
template<typename T>
void dbgp(std::vector<T> v)
{
    std::cout << dbg(v) << '\n';
}

// Stack
template<typename T>
std::string dbg(std::stack<T> s)
{
    std::vector<T> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    std::reverse(v.begin(), v.end());
    return dbg(v);
}
template<typename T>
void dbgp(std::stack<T> s)
{
    std::cout << dbg(s) << '\n';
}

// Queue
template<typename T>
std::string dbg(std::queue<T> q)
{
    std::vector<T> v;
    while(!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
    return dbg(v);
}
template<typename T>
void dbgp(std::queue<T> q)
{
    std::cout << dbg(q) << '\n';
}

// Deque
template<typename T>
std::string dbg(std::deque<T> dq)
{
    std::stringstream ss;
    if(dq.empty())
    {
        ss << "EMPTY";
        return ss.str();
    }
    for(auto i: dq)
        ss << i << (i==dq.back()?"":", ");
    return ss.str();
}
template<typename T>
void dbgp(std::deque<T> dq)
{
    std::cout << dbg(dq) << '\n';
}

// Iterator
template<typename T>
std::string dbg(T* begin, T* end)
{
    std::vector<T> v;
    for(auto i = begin; i != end; i++)
        v.push_back(*i);
    return dbg(v);
}
template<typename T>
void dbgp(T* begin, T* end)
{
    std::cout << dbg(begin, end) << '\n';
}
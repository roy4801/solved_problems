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
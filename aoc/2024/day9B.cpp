#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;
using P = pair<int,int>;
#define ID first
#define SIZ second
#define PTR(x) (void*)((uint64_t)(x) & 0xFFFFF)

string in;
vector<ULL> s;
int n;

void input()
{
    cin >> in;
    n = in.size();
}

struct Chunk
{
    enum Type
    {
        Free,
        Used
    } type;
    int id;
    int size;
    Chunk* prev;
    Chunk* next;
};

void solve()
{
    Chunk* chunk_head = nullptr, *chunk_end = nullptr, **p = &chunk_head;

    auto insert_chunk = [&](Chunk* pos, Chunk* ch)
    {
        auto prev = pos, next = pos->next;
        
        prev->next = ch;
        ch->prev = prev;

        if(next)
        {
            next->prev = ch;
        }
        else
        {
            chunk_end = ch;
        }
        ch->next = next;
    };
    auto debug = [&]()
    {
        auto cur = chunk_head;
        while(cur)
        {
            if(cur->type == Chunk::Type::Used)
            {
                for(int i = 0; i < cur->size; i++)
                    cout << to_string(cur->id);
            }
            else
            {
                for(int i = 0; i < cur->size; i++)
                    cout << '.';
            }
            cur = cur->next;
        }
        cout << '\n';
    };

    int id = 0;
    for(int i = 0; i < n; i++)
    {
        Chunk* c = new Chunk;
        if(i % 2 == 0) // used
        {
            c->type = Chunk::Type::Used;
            c->id = id++;
            c->size = in[i]-'0';
            *p = c;
            p = &(*p)->next;
            chunk_end = c;
        }
        else // free
        {
            c->type = Chunk::Type::Free;
            c->size = in[i]-'0';
            *p = c;
            p = &(*p)->next;
            chunk_end = c;
        }
    }
    
    list<Chunk*> used;
    Chunk* cur = chunk_head, *prev = nullptr;
    while(cur)
    {
        if(cur->type == Chunk::Type::Used)
            used.emplace_back(cur); 
        cur->prev = prev;
        prev = cur;
        cur = cur->next;
    }

    //debug();

    // i = used chunk
    // j = free chunk
    for(auto i = chunk_end; i != nullptr; i = i->prev)
    {
        if(i->type != Chunk::Used)
            continue;

        //printf("cur=%d ", i->id);

        for(auto j = chunk_head; j != nullptr; j = j->next)
        {
            if(i == j)
                break;
            if(j->type != Chunk::Free)
                continue;

            if(j->size == i->size)
            {
                i->type = Chunk::Free;
                j->type = Chunk::Used;
                j->id = i->id;
                break;
            }
            else if(j->size > i->size)
            {
                int a = i->size, b = j->size - i->size;

                i->type = Chunk::Free;

                j->type = Chunk::Used;
                j->size = a;
                j->id = i->id;

                Chunk* f = new Chunk;
                f->type = Chunk::Free;
                f->size = b;
                insert_chunk(j, f);

                break;
            }
        }

        //debug();
    }

    vector<ULL> s;
    cur = chunk_head;
    while(cur)
    {
        if(cur->type == Chunk::Type::Used)
        {
            for(int i = 0; i < cur->size; i++)
                s.emplace_back(cur->id);
        }
        else
        {
            for(int i = 0; i < cur->size; i++)
                s.emplace_back(-1);
        }
        cur = cur->next;
    }

    ULL ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == (ULL)-1)
            continue;
        ans += s[i] * i;
    }
    cout << ans << '\n';
}

int main()
{
    freopen("/home/roy4801/Programming/solved_problems/aoc/2024/day9B.in", "r", stdin);
    setvbuf(stdout, NULL, _IONBF, 0);

    input();
    solve();
}

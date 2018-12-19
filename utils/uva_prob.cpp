#include <bits/stdc++.h>
using namespace std;

#define MAX_CAT 200

#define USE_FILE 0

#if USE_FILE
    #define IN fstm
#else
    #define IN cin
#endif


fstream fstm;
vector<int> ll[MAX_CAT];

ofstream oFile;

pair<bool, string> getStat(int n)
{
    string target = to_string(n) + " - ", prob_str;
    fstream f("../uva/" + to_string(n) + ".cpp");

    string s;
    bool AC = false;
    while(getline(f, s))
    {
        size_t pos = s.find(target);
        if((pos = s.find(target)) != std::string::npos)
        {
            prob_str = s.substr(pos + target.length());
            // cout << "Found" << '\n';
        }

        if((pos = s.find("AC")) != std::string::npos)
        {
            AC = true;
        }
    }
    
    if(f.is_open())
        f.close();

    return make_pair(AC, prob_str);
}

int main()
{
    bool AC;
    string prob_str;
    //
#if USE_FILE
    IN.open("temp.txt");
#endif
    
    oFile.open("README.md");
    string s;
    // in
    int min_num = INT_MIN;
    int ac_num = 0, total_prob = 0;

    while(IN >> s)
    {
        int sn = stod(s);
        if(getStat(sn).first)
            ac_num++;
        total_prob++;
        ll[sn / 100].push_back(sn);
    }
    // out
    oFile << "# Uva" << '\n';
    oFile << '\n' << "> ";
    oFile << "AC/Total = " << ac_num << " / " << total_prob << "\n\n";

    for(int i = 0; i < MAX_CAT; i++)
    {
        if(ll[i].size() > 0)
        {
            oFile << "## Volume " << i << '\n';
            for(auto j : ll[i])
            {
                tie(AC, prob_str) = getStat(j);
                oFile << "* " << (AC ? "[x] " : "[ ] ") << j << " - " << prob_str << '\n';
            }
            oFile << '\n';
        }
    }
    //
#if USE_FILE
    if(fstm.is_open())
        fstm.close();
#endif
    if(oFile.is_open())
        oFile.close();
    return 0;
}
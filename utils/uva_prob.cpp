#include <bits/stdc++.h>
using namespace std;

#define MAX_CAT 200

fstream fstm;
vector<int> ll[MAX_CAT];

ofstream oFile;

#ifdef __APPLE__
#include <dirent.h>

vector<string> listDir(const string dir)
{
    static const char* donwant[] = {".DS_Store", "a.out", "README.md", "_ref"};
    vector<string> list;
    struct dirent *dirEnt;
    DIR *pDir;
    // Open dir
    if(!(pDir = opendir(dir.c_str())))
    {
        cout << "Cannot open dir " + dir << '\n';
        return list;
    }
    // Read dir
    while(dirEnt = readdir(pDir))
    {
        if(dirEnt->d_type != DT_DIR)
        {
            // Find donwant pattern
            bool found = false;
            for(int i = 0; i < sizeof(donwant)/sizeof(const char*); i++)
            {
                if(strstr(dirEnt->d_name, donwant[i]))
                {
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                // Strip .cpp
                istringstream iss(dirEnt->d_name);
                string s;
                getline(iss, s, '.');
                // add
                list.push_back(s);
            }
        }
    }

    closedir(pDir);
    return list;
}
#endif

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
    auto list = listDir("../uva/");
    //
    oFile.open("../uva/README.md", ios::out | ios::trunc);
    //
    int min_num = INT_MIN;
    int ac_num = 0, total_prob = 0;
    // Read problem nums
    for(auto i = list.begin(); i < list.end(); i++)
    {
        int sn = stod(*i);
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
    if(oFile.is_open())
        oFile.close();
    return 0;
}
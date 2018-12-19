#include <bits/stdc++.h>
using namespace std;

#define MAX_CAT 200

fstream fstm;
vector<int> ll[MAX_CAT];

ofstream oFile;

pair<bool, string> getStat(int n)
{
    string target = to_string(n) + " - ", prob_str;
    fstream f("../solved_problems/uva/" + to_string(n) + ".cpp");

    // if(f.is_open())
        // cout << "Opened a file" << '\n';

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
    
    return make_pair(AC, prob_str);
}

int main()
{
    bool AC;
    string prob_str;
    //
    fstm.open("temp.txt");
    oFile.open("README.md");
    string s;

    int min_num = INT_MIN;
    while(fstm >> s)
    {
    	int sn = stod(s);
    	ll[sn / 100].push_back(sn);
    }
    oFile << "# Uva" << '\n';
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

    if(fstm.is_open())
    	fstm.close();
    if(oFile.is_open())
    	oFile.close();
    return 0;
}
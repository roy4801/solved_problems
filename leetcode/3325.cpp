/*
 * Leetcode diff id. title
 * author: roy4801
 * (C++)
 */
#include <bits/stdc++.h>
using namespace std;
#include "helper.h"

typedef pair<int, int> P;
typedef long long int LL;
#define arr array
#define PB push_back
#define MP make_pair
#define X first
#define Y second

class Solution {
public:
    int numberOfSubstrings(string s, int K)
    {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int cnt[26] = {0};
            for(int j = i; j < n; j++)
            {
                cnt[s[j]-'a']++;

                for(int k = 0; k < 26; k++)
                    if(cnt[k] >= K)
                    {
                        ans += n-j;
                        goto out;
                    }
            }
out:
            ;
        }
        return ans;
    }
};

int main()
{
    DBG(Solution{}.numberOfSubstrings("abacb", 2));
    DBG(Solution{}.numberOfSubstrings("abcde", 1));
    DBG(Solution{}.numberOfSubstrings("hxccgfp", 1));
    DBG(Solution{}.numberOfSubstrings("sosvhouwfupcspghmghuftqymsifbdsokmnawzzonfoormzobpuylldzorjrqinznlxxqxvuduaxfhzylirscbtlncktgiimqczcnodozjfdjoqbqwkyyxlifrlpbypyjfyjmhqdwuobimrciupmndozmihpoglvsvfjyrsdagcpqpetujczzcklclxsmrwidkkrimzgyxsvuuldfqitfnyujnqdzskeybjsydifxcxldbnmysfsztdzzyvnkthcbyemtauypfxnylwnffkjzirobjksmrrvfextvtsrehoxztlyooutdzcjjlasrcsgreafvmfaiqbfowfivnpwjtbljfmvcrsezpoomnbhqojclikaizcnxtosivhnjuazbvlmfrcamuyzvfxmjpkowhuefntanqvygzukqlxrrpsbuscjesdxilsjodkjjzhfrzymiaeedjsfpquiustwncrogdpfyhpvwhlbwsejifdmvjcaridevqmtrknvnahcelfpwxyewctwfarqrffbvwbqricsysqeocywzqlzravlmldopvmanhdphzvcevlmjatavbbnlpohifkkcuybhqxqzmfxbcldvirkoxxuntghbajgfmyvqdagiazorjkolymmuqhrdmpqofaieojplsumimkwscrzfjdjcwryxsjlhjegbohsyrteqlnwjblxwuetbjevgvduuathjiymrawlsezwhlxpxmzvpvyhxkkhigcspwzgzlphshiwoqobttxxwkorxlzwlysbrvsyptxfcgsbogwdzngszersxngrhbjsofzdsmsrhwupprzzzxcwhyolvuyawiszhptufstnvrdmcnrrealfeffblkveosnqnopsyttqwfuagdgylapjqbgsdpgrzifuoeyjikdmeorzvoetxoubdgtvverbzcbsocogrycgeumzyukjeyvkwffyjgmzyggbpidtuhhimgtkwbgjekealyweincyheqqjtrxplbzucwpadgfmwctprtbjgwenlxtpuvbhmreygdoaenoxnuofhodkgliqbephszpxggzbfswstblmymlvwxwbfmseaptfagugkjhnwtzuylltwsfsjznywwfjuiwvmrmimfezodiprspziufazbtemvgllthudleyzpdugkfxryefuaqoyjyrpnpvasduznwrbclievxjjxvncvmrxayodxkgwbjrtspovnzmyjparuhojotmbrybsxgaafueudtoyogxdwatmvzdqqmmfvgtxecjjerruxohiwldpwkskikbwhrgitrlimgyqilhuwgrkglvvnwqicxzpehsyuynhpjscc", 6));
}

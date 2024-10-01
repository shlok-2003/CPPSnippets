#pragma once
#include <iostream>
#include <vector>
using namespace std;

//? Longest 

struct KMP {
    static vector<int> kmp(const string& s) {
        vector<int> lps(s.size(), 0);

        for(int i = 1; i < (int)s.size(); i++)
        {
            int prev_idx = lps[i - 1];      //? get the previous index, and check if the current character is same as the previous index character

            while(prev_idx > 0 && s[i] != s[prev_idx])
            {
                prev_idx = lps[prev_idx - 1];      //? if not same, then get the previous index of the previous index
            }

            lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);      //? if same, then increment the length of the longest prefix suffix
        }

        return lps;     
    }
};

bool string_matching(const string& s1, const string& pattern) {
    string s = pattern + "#" + s1;
    vector<int> lps = KMP::kmp(s);

    for(int i = pattern.size(); i < (int)s.size(); i++)
    {
        int ele = lps[i];
        if(ele == pattern.size())
        {
            int idx = i - 2 * pattern.size();       //? to get the index, we need to subtract the pattern size twice, because we have added pattern size + 1
            if(idx >= 0)
            {
                return true;
            }
        }
    }

    return false;
}
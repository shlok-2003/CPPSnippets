#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool string_matching(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();

    for(int i = 0; i <= n - m; i++)
    {
        string curr = s1.substr(i, m);      //? get the substring from the s1, and check if matches with the s2 string

        if(curr == s2)  return true;
    }

    return false;
}
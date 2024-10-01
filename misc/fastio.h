#pragma once
#include <iostream>
using namespace std;

static const int _ = []() {
    // #define int         long long int
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

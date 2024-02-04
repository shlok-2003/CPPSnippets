#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//! Colors
const auto ANSI_RED = "\x1b[31m";
const auto ANSI_GREEN = "\x1b[32m";
const auto ANSI_YELLOW = "\x1b[33m";
const auto ANSI_BLUE = "\x1b[34m";
const auto ANSI_RESET = "\x1b[0m";

//! Brackets
static const auto lbrac = "[ ";
static const auto rbrac = "]";
static const auto lparam = "{ ";
static const auto rparam = " }";
static const auto comma = ",";
static const auto space = " ";
static const auto variable = "var";
static const auto colon = " : ";

void _print(const int t)                { cerr << ANSI_RED << t << ANSI_RESET; }
void _print(const long long t)          { cerr << ANSI_RED << t << ANSI_RESET; }
void _print(const unsigned long long t) { cerr << ANSI_RED << t << ANSI_RESET; }
void _print(const char t)               { cerr << ANSI_RED << t << ANSI_RESET; }
void _print(const string t)             { cerr << ANSI_RED << t << ANSI_RESET; }
void _print(const double t)             { cerr << ANSI_RED << t << ANSI_RESET; }
void _print(const long double t)        { cerr << ANSI_RED << t << ANSI_RESET; }

template <class T, class V>
void _print(pair<T, V> &v);

template <class T>
void _print(vector<T> &v);

template <class T>
void _print(set<T> &v);

template <class T, class V>
void _print(unordered_set<T, V> &v);

template <class T, class V>
void _print(map<T, V> &v);

template <class T, class V>
void _print(unordered_map<T, V> &v);

template <class T>
void _print(multiset<T> &v);

template <class T, class V>
void _print(pair<T, V> &v)
{
    cerr << lparam;
    _print(v.first);

    cerr << string(comma) + space;

    _print(v.second);
    cerr << rparam;
}

template <class T>
void _print(vector<T> &v)
{
    cerr << lbrac;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        _print(*it);
        if (next(it) != v.end())
            cerr << string(comma) + space;
        else
            cerr << space;
    }
    cerr << rbrac;
}

template <class T>
void _print(set<T> &v)
{
    cerr << lbrac;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        _print(*it);
        if (next(it) != v.end())
            cerr << string(comma) + space;
        else
            cerr << space;
    }
    cerr << rbrac;
}

template <class T>
void _print(unordered_set<T> &v)
{
    cerr << lbrac;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        _print(*it);
        if (next(it) != v.end())
            cerr << string(comma) + space;
        else
            cerr << space;
    }
    cerr << rbrac;
}

template <class T>
void _print(multiset<T> &v)
{
    cerr << lbrac;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        _print(*it);
        if (next(it) != v.end())
            cerr << string(comma) + space;
        else
            cerr << space;
    }
    cerr << rbrac;
}

template <class T, class V>
void _print(map<T, V> &v)
{
    cerr << lbrac << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cerr << "\t";
        _print(it->first);

        cerr << colon;

        _print(it->second);
        cerr << endl;
    }
    cerr << rbrac;
}

template <class T, class V>
void _print(unordered_map<T, V> &v)
{
    cerr << lbrac << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cerr << "\t";
        _print(it->first);

        cerr << colon;

        _print(it->second);
        cerr << endl;
    }
    cerr << rbrac;
}

#define debug(x)                                                                   \
    cerr << ANSI_GREEN << variable << space << #x << colon << space << ANSI_RESET; \
    _print(x);                                                                     \
    cerr << endl;

//! Undef Colors
#undef ANSI_RED
#undef ANSI_GREEN
#undef ANSI_YELLOW
#undef ANSI_BLUE
#undef ANSI_RESET

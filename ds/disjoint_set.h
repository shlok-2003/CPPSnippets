#pragma once
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DisjointSet {
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n+1, 0); size.resize(n+1, 1); parent.resize(n+1);    //? for both (0 and 1)-based indexing
        iota(parent.begin(), parent.end(), 0);
    }

    int findUParent(int node) {                        //? Find Ultimate Parent
        if(node == parent[node])    return node;

        return parent[node] = findUParent(parent[node]);
    }

    //! Time Complexity of Union_BySize and Union_ByRank is O(4'alpha')
    void union_ByRank(int u, int v) {                //? Union By Rank
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)    return;

        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
            parent[ulp_v] = ulp_u, rank[ulp_u]++;
    }

    void union_BySize(int u, int v) {                //? Union By Size
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)    return;

        if(size[ulp_u] < size[ulp_v])
            parent[ulp_u] = ulp_v, size[ulp_v] += size[ulp_u];
        else if(size[ulp_u] >= size[ulp_v])
            parent[ulp_v] = ulp_u, size[ulp_u] += size[ulp_v];        // same conditions will apply for '>' and '=' conditions. 
                                                                    // So, merge it in same condition
    }
};
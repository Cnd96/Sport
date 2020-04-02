#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
vector<vector<int>> vec;
int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int V, m, a, b;
        cin >> V >> m;
        int arr[V][V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
               arr[i][j]=2;
            }
            
        } 

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            arr[a][b] = 1;
            arr[b][a] = 1;
        }

        
        
        int parent[V];
        int key[V];
        bool mstSet[V];
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;
        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minKey(key, mstSet, V);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (arr[u][v] && mstSet[v] == false && arr[u][v] < key[v])
                    parent[v] = u, key[v] = arr[u][v];
        }

        int res=0;
        for (int i = 1; i < V; i++)
        res+= arr[i][parent[i]] ;

        cout << "Case #" << tt << ": "<<res
             << "\n";
    }
    return 0;
}

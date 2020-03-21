#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue> 
using namespace std;
int nodes = 9;
int edges = 9;

int main()
{
    vector<int> pdata[nodes];
    // int aa[edges][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {3, 4}};
     int aa[edges][2] = {{0, 1}, {0, 6}, {1, 7}, {1, 2}, {2, 3},{2,5},{3,4},{3,8},{4,5}};

    for (int i = 0; i < edges; i++)
    {
        pdata[aa[i][0]].push_back(aa[i][1]);
        pdata[aa[i][1]].push_back(aa[i][0]);
    }

    int nodesData[nodes];
    for (int i = 0; i < nodes; i++)
    {
        nodesData[i] = pdata[i].size();
    }
    bool visited[nodes];
    memset(visited, false, sizeof(visited));
    
    queue <int> q;
    while (1)
    {
        for (int i = 0; i < nodes; i++)
        {
            if ((nodesData[i]==1)&&(!visited[i]))
            {
                q.push(i);
            }   
        }
        if(q.empty())break;
        while (!q.empty())
        {
            int temp=q.front();
            q.pop();
            visited[temp]=true;
            for (int i = 0; i < pdata[temp].size(); i++)
            {
                if(visited[pdata[temp][i]]){
                    continue;
                }
                nodesData[pdata[temp][i]]--;
            }
            
        }
    }

    vector<int> cycle;

    for (int i = 0; i < nodes; i++)
    {
        if(!visited[i]){
            cycle.push_back(i);
        }
    }
    for (int i = 0; i < cycle.size(); i++)
    {
        cout<<cycle[i]+1<<" ";
    }
    

    return 0;
}

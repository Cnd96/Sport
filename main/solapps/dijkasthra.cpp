#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int V = 9;
bool sortcol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[1] < v2[1];
}

int main()
{

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    bool found[V];
    int distance[V];
    int neighbour[V];
    for (int i = 0; i < V; i++)
    {
        found[i] = false;
        distance[i] = INT_MAX;
    }
    found[0] = true;
    distance[0] = 0;
    neighbour[0] = 0;
    vector<vector<int>> pdata;
    int currentNode = 0;
    int totalFound = 1;

    while (1)
    {
        for (int i = 0; i < V; i++)
        {
            if (!found[i] && (graph[currentNode][i] != 0))
            {
                bool foundInP = false;
                for (int j = 0; j < pdata.size(); j++)
                {
                    if (pdata[j][0] == i)
                    {

                        foundInP = true;
                        if (distance[currentNode] + graph[currentNode][i] < pdata[j][1])
                        {
                            pdata[j][1] = distance[currentNode] + graph[currentNode][i];
                            neighbour[i] = currentNode;
                        }
                        break;
                    }
                }
                if (!foundInP)
                {
                    //  cout<<distance[currentNode] + graph[currentNode][i]<<"  i  "<<i<<endl;
                    vector<int> temp(3);
                    temp[0] = i;
                    temp[1] = distance[currentNode] + graph[currentNode][i];
                    pdata.push_back(temp);
                    neighbour[i] = currentNode;
                }
            }
        }
        sort(pdata.begin(), pdata.end(), sortcol);
        found[pdata[0][0]] = true;
        distance[pdata[0][0]] = pdata[0][1];
        totalFound++;
        currentNode = pdata[0][0];

        if (totalFound == V)
            break;
        // if (found[3])
        //     break;
        pdata.erase(pdata.begin());
    }
    cout << endl;
    for (int j = 0; j < V; j++)
    {
        cout << j << " " << distance[j] << " n " << neighbour[j] << endl;
    }
    return 0;
}

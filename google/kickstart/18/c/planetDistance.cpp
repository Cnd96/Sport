#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int noNodes, one, two,assignedNo=0;
        cin >> noNodes;
        vector<int> pdata[noNodes];
        int nodesData[noNodes];
        bool visited[noNodes];
        queue<int> q;
        bool distanceAssinged[noNodes];
        int distanceData[noNodes];
        memset(distanceData, INT_MAX, sizeof(distanceData));
        memset(visited, false, sizeof(visited));
        memset(distanceAssinged, false, sizeof(distanceAssinged));
        int currentDistance = 0;
        for (int i = 0; i < noNodes; i++)
        {
            cin >> one >> two;
            one--;
            two--;
            pdata[one].push_back(two);
            pdata[two].push_back(one);
        }

        for (int i = 0; i < noNodes; i++)
        {
            nodesData[i] = pdata[i].size();
        }
        while (1)
        {
            for (int i = 0; i < noNodes; i++)
            {
                if ((nodesData[i] == 1) && (!visited[i]))
                {
                    q.push(i);
                }
            }
            if (q.empty())
                break;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                visited[temp] = true;
                for (int i = 0; i < pdata[temp].size(); i++)
                {
                    if (visited[pdata[temp][i]])
                    {
                        continue;
                    }
                    nodesData[pdata[temp][i]]--;
                }
            }
        }

        for (int i = 0; i < noNodes; i++)
        {
            if (!visited[i])
            {
                distanceData[i] = currentDistance;
                distanceAssinged[i] = true;
                assignedNo++;
            }
        }
        // currentDistance++;

        // cout<<currentDistance<<endl;
        while (assignedNo<noNodes)
        {
            for (int i = 0; i < noNodes; i++)
            {
                if (distanceData[i] == currentDistance)
                {
                    for (int j = 0; j < pdata[i].size(); j++)
                    {
                        if (!distanceAssinged[pdata[i][j]])
                        {
                            distanceData[pdata[i][j]] = currentDistance+1;
                            distanceAssinged[pdata[i][j]]=true;
                            assignedNo++;
                        }
                    }
                }
            }
            currentDistance++;
        }
        cout << "Case #" << tt << ": ";
        for (int i = 0; i < noNodes; i++)
        {
            cout<<distanceData[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// 3
// 9
// 1 2
// 1 7
// 2 8
// 2 3
// 3 4
// 3 6
// 4 5
// 4 9
// 5 6
// 5
// 1 2
// 2 3
// 3 4
// 2 4
// 5 3
// 3
// 1 2
// 3 2
// 1 3

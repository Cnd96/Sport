#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    string ss="rgcdae";

	vector<string> pdata;

    for (int i = 0; i < ss.size(); i++)
    {
        for (int j = i; j< ss.size(); j++)
        {
			string temp="";
            for (int k = i; k <=j; k++)
            {
               temp.push_back(ss[k]);
            }
			sort(temp.begin(),temp.end());
			pdata.push_back(temp);
        }   
    }
	for (int i = 0; i < pdata.size(); i++)
	{
		cout<<pdata[i]<<endl;
	}
	
}

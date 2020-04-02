#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;



int main()
{

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        string s;
        int x,k,res=0;
        int alb[26]={0};
        int del[26]={0};
        cin>>s>>k>>x;
        
        for (int i = 0; i < s.size(); i++)
        {
            alb[(s[i]- '0'-49)]++;

            if( alb[(s[i]- '0'-49)]>x){
                if(del[(s[i]- '0'-49)]<k){
                    del[(s[i]- '0'-49)]++;
                    alb[(s[i]- '0'-49)]--;
                }
            }
            else
            {
               res++; 
            }
             if( alb[(s[i]- '0'-49)]>x){
                 break;
             }
        }
        

          cout <<res<< "\n";
    }
    return 0;
}


// abcdefagahai
// 0 1
#include "bits/stdc++.h"
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;


int main()
{

    int t;
    cin>>t;
    for (int i = 1; i <=t; i++)
    {
       int n;
       cin>>n;
       string names[3];
       for (int j = 0; j <3; j++)
       {
        //  string s;
         cin>>names[j];
       }

        while(true){
            if((names[0][0]==names[1][0])&&(names[0][0]==names[2][0])){
                names[0].erase(0, 1); 
                names[1].erase(0, 1); 
                names[2].erase(0, 1); 
            }
            else
            {
                break;
            }
            
        }
        char matchingChar;
        if((names[0][0]==names[1][0])||(names[0][0]==names[2][0])||(names[1][0]==names[2][0])){
                if((names[0][0]==names[1][0])){
                    matchingChar=names[0][0];
                         while(true){
                            if((names[0][0]==names[1][0])){
                                names[0].erase(0, 1); 
                                names[1].erase(0, 1); 
                            }
                            else
                            {
                                break;
                            }
                        }
                        if((names[0][0]==matchingChar)&&(names[1][0]==names[2][0])){
                            cout<<"Case #"<<i<<": NO YES NO"<<endl;
                        }
                        else if ((names[1][0]==matchingChar)&&(names[0][0]==names[2][0]))
                        {
                            cout<<"Case #"<<i<<": YES NO NO"<<endl;
                        }
                        else
                        {
                           cout<<"Case #"<<i<<": YES YES NO"<<endl;
                        }                     
                }
                else if ((names[0][0]==names[2][0]))
                {
                     matchingChar=names[0][0];
                         while(true){
                            if((names[0][0]==names[2][0])){
                                names[0].erase(0, 1); 
                                names[2].erase(0, 1); 
                            }
                            else
                            {
                                break;
                            }
                        }
                        if((names[0][0]==matchingChar)&&(names[2][0]==names[1][0])){
                            cout<<"Case #"<<i<<": NO NO YES"<<endl;
                        }
                        else if ((names[2][0]==matchingChar)&&(names[0][0]==names[1][0]))
                        {
                            cout<<"Case #"<<i<<": YES NO NO"<<endl;
                        }
                        else
                        {
                          cout<<"Case #"<<i<<": YES NO YES"<<endl;
                        }
                }
                else if ((names[2][0]==names[1][0]))
                {
                     matchingChar=names[1][0];
                         while(true){
                            if((names[1][0]==names[2][0])){
                                names[1].erase(0, 1); 
                                names[2].erase(0, 1); 
                            }
                            else
                            {
                                break;
                            }
                        }
                        if((names[1][0]==matchingChar)&&(names[2][0]==names[0][0])){
                            cout<<"Case #"<<i<<": NO NO YES"<<endl;
                        }
                        else if ((names[2][0]==matchingChar)&&(names[1][0]==names[0][0]))
                        {
                           cout<<"Case #"<<i<<": NO YES NO"<<endl;
                        }
                        else
                        {
                          cout<<"Case #"<<i<<": NO YES YES"<<endl;
                        }
                }
        }
        else
        {
             cout<<"Case #"<<i<<": YES YES YES"<<endl;
        }
    }  
    return 0;  
}
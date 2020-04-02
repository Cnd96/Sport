#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
//33 , 21, 50, 41, 60 
int arr[] ={ 34,10, 22, 9, 33, 21, 50, 41, 60,65,75,32,54,66,7,88,92,2,45,102,103,55,433,535,53,435,43,454}; 
int  n = sizeof(arr)/sizeof(arr[0]); 
int getRes(int curIndex,int curLen,int curNo){
    int length=curLen;
    int tlength=curLen;
    for (int i = curIndex+1; i < n; i++)
    {
       
        if(arr[i]>arr[curNo]){
            int temp=max(getRes(i,(tlength+1),i),getRes(i,tlength,curNo));
            length=max(length,temp);
        }
    }
    return length;
}

int main()
{
    for (int i = 0; i < n; i++)
    {
       cout<<getRes(i,1,i)<<endl;
    }

    int ldata[n];
    ldata[0]=1;

    for (int i = 1; i < n; i++)
    {
       ldata[i]=1;
       for (int j = 0; j < i; j++)
       {
           if((arr[i]>arr[j])&&(ldata[i]<=ldata[j])){
               ldata[i]= ldata[j]+1;
           }
       }
    //    cout<<ldata[i];
    }
    

    cout<<*max_element(ldata, ldata+n); 

    return 0;
}

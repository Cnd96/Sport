#include "bits/stdc++.h"
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

void getMaxSubArr(int a[], int size){
   int tempStart, startp=0,endp=0,maxCcurrent=a[0], maxSum=a[0];
   for (int i = 1; i < size; i++)
   {
       maxCcurrent=maxCcurrent+a[i];
       if(maxCcurrent>maxSum){
           maxSum=maxCcurrent;
           endp=i;
           startp=tempStart;
       }
       if (maxCcurrent<0)
       {
           maxCcurrent=0;
           tempStart=i+1;
       }
       
   }
   cout<<maxSum<<" "<<startp<<" "<<endp<<endl;
}

int main()
{
   int a[] = {-2, -3, 4, -3, -2, 1, 5,-2,2,-1,2, -3}; 
   int n = sizeof(a)/sizeof(a[0]); 
    getMaxSubArr(a,n);
}
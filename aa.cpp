#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define fr(i,s,e) for(i=s;i<e;i++)
#define ms(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int mxn=1e5+1;
int dp[100][100001],n;
int arr[100];
int func(int i,int sum)
{
    if(i<0)
        return 0;
   if(dp[i][sum]!=-1)
       return dp[i][sum];
    int ans=0;
    if(sum<=6*arr[i])
        ans=1+func(i-1,sum+arr[i]);
    ans=max(ans,func(i-1,sum));
    return dp[i][sum]=ans;
}
int main(){
//    freopen("A.in","r",stdin);
//    freopen("sol.out","w",stdout);
  int t=1,tt=1;
  cin>>t;
    while(t--){
        ms(dp,-1);
        int i;
        cin>>n;
        fr(i,0,n)
        cin>>arr[i];
        reverse(arr,arr+n);

        cout<<"Case #"<<tt++<<": "<<func(n-1,0)<<"\n";
    }
  return 0;
  }
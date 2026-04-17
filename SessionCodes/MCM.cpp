#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp)
{
    if(i==j) return 0;
    int ans=1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=1;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+solve(arr,i,k,dp)+solve(arr,k+1,j,dp);
        dp[i][j]=steps;
        if(steps<ans) ans=steps;
    }
    return dp[i][j]=ans;
}
int main()
{
    int n;
    cin>>n;    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans=solve(arr,0,n-1,dp);
    cout<<ans<<endl;
    return 0;
}
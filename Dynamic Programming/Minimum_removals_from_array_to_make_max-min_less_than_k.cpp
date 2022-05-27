#include<bits/stdc++.h>
#define int long long int
using namespace std;
int dp[1001][1001];
int solve(int a[], int i, int j, int k)
{
    if (i >= j)
        return 0;

    if ((a[j] - a[i]) <= k)
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    return dp[i][j] = 1 + min(solve(a, i + 1, j, k),solve(a, i, j - 1, k));
                           
}
int32_t main(){
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k;
    cin>>k;
    memset(dp,-1,sizeof(dp));
    sort(a,a+n);
    if(n==1) cout<<0;
    else{
        cout<<solve(a,0,n-1,k);
    }
    return 0; 
}
class Solution {
public:
int solve(int i,int fil,vector<int>&nums,int n,int k,vector<vector<int>>&dp)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i][fil]!=-1)
    {
        return dp[i][fil];
    }
    if(fil!=0)
    {
        int temp=INT_MAX,temp2;
        if(fil+1+nums[i]<=k)
        {
            temp=solve(i+1,fil+1+nums[i],nums,n,k,dp);
        }
        int count=k-fil;
        temp2=count*count+solve(i,0,nums,n,k,dp);
        return dp[i][fil]=min(temp,temp2);
    }
    else
    {
        return dp[i][fil]=solve(i+1,nums[i],nums,n,k,dp);
    }
}
    int solveWordWrap(vector<int>nums, int k) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,0,nums,n,k,dp);
    } 
};
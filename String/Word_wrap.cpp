class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        vector<vector<int>> vec(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            vec[i][i]=k-nums[i];
            for(int j=i+1;j<n;j++)
            {
                vec[i][j]=vec[i][j-1]-nums[j]-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(j==n-1 && vec[i][j]>0)
                {
                    vec[i][j]=0;
                }
                if(vec[i][j]<0)
                {
                    vec[i][j]=INT_MAX;
                }
                else
                {
                    vec[i][j]=vec[i][j]*vec[i][j];
                }
            }
        }
        vector<int> min(n),ans(n);
        for(int i=n-1;i>=0;i--)
        {
            min[i]=vec[i][n-1];
            ans[i]=n;
            for(int j=n-1;j>i;j--)
            {
                if(vec[i][j-1]==INT_MAX)
                {
                    continue;
                }
                if(min[i]>(vec[i][j-1]+min[j]))
                {
                    min[i]=vec[i][j-1]+min[j];
                    ans[i]=j;
                }
            }
        }
        return min[0];
    } 
};

//Method 2
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

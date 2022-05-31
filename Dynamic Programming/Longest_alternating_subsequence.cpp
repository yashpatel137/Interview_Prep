//Method 1 TC=O(n) SC=O(1)
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums)
		{
		    int n=nums.size();
		    if(n==1)
		    {
		        return 1;
		    }
		    int mx=1,mn=1;
		    for(int i=1;i<n;i++)
		    {
		        if(nums[i]>nums[i-1])
		        {
		            mx=mn+1;
		        }
		        else if(nums[i]<nums[i-1])
		        {
		            mn=mx+1;
		        }
		    }
		    return max(mx,mn);
		}
};

//Method 2 TC=O(n^2) SC=(On^2)
int AlternatingaMaxLength(vector<int>&nums)
{
     int n = nums.size();
     if(n == 1) return (1);
     int dp[n][2];
     for(int i = 0; i < n; i++)
         dp[i][0] = dp[i][1] = 1;
     int mx = 0;
     for(int i = 1; i < n; i++)
     {
         for(int j = 0; j < i; j++)
         {
             if(nums[j] < nums[i])
             {
                 dp[i][0] = max(dp[i][0],dp[j][1]+1);
             }
             else if(nums[j] > nums[i])
             {
                 dp[i][1] = max(dp[i][1],dp[j][0]+1);
             }
         }
         mx = max({mx,dp[i][0],dp[i][1]});
     }
     return (mx);
 }
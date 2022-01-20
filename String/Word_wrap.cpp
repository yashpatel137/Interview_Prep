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
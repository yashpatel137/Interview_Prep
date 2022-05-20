class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        int dp[n][n];
        for(int i=1;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
                }
            }
        }
        return dp[1][n-1];
    }
};
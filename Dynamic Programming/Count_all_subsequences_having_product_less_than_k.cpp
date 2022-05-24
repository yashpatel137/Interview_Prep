//Method 1 dp TC=O(n*k) SC=O(n*k)
int productSubSeqCount(vector<int> &arr, int k)
{
	int n = arr.size();
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) 
        {
			dp[i][j] = dp[i][j - 1];
			if (arr[j - 1] <= i)
				dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
		}
	}
	return dp[k][n];
}


//Method 2 TC=O(n) SC=O(1)
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        unsigned long long prod=1;
        int i=0,j=0,ans=0;
        while(i<n and j<n)
        {
            prod *= a[j];
            while(prod>=k && i<j)
            {
                prod /= a[i++];
            }
            if(prod<k)
            {
                ans+=(j-i+1);
            }
            j++;
        }
        return ans;
    }
};
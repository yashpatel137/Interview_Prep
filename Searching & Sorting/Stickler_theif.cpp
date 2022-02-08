class Solution
{
    public:
    int solve(int arr[],int i,vector<int> &ans)
    {
        if(i<=-1)
        {
            return 0;
        }
        if(ans[i]!=-1)
        {
            return ans[i];
        }
        int op1=arr[i]+solve(arr,i-2,ans);
        int op2=solve(arr,i-1,ans);
        return ans[i]=max(op1,op2);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> ans(n,-1);
        return solve(arr,n-1,ans);
    }
};
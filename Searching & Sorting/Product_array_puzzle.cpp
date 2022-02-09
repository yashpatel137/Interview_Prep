class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) 
    {
        vector<long long int> ans(n,1);
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=ans[i+1]*nums[i+1];
        }
        long long int tmp=1;
        for(int i=0;i<n;i++)
        {
            ans[i]=ans[i]*tmp;
            tmp=tmp*nums[i];
        }
        return ans;
    }
};
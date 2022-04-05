class Solution {
  public:
    void solve(int j,int sum,vector<int>temp,vector<vector<int>> &ans,vector<int> &A)
    {
        if(sum==0)
        {
            ans.push_back(temp);
        }
        if(sum<0)
        {
            return;
        }
        for(int i=j;i<A.size();i++)
        {
            if(sum-A[i]>=0)
            {
                j=i;
                temp.push_back(A[i]);
                solve(j,sum-A[i],temp,ans,A);
                temp.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) 
    {
        vector<vector<int>> ans;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        vector<int> temp;
        solve(0,B,temp,ans,A);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
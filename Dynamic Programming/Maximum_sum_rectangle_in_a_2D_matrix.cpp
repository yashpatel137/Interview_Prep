class Solution {
  public:
    int kaden(vector<int> &temp)
    {
        int mx=INT_MIN,sum=0;
        for(int i=0;i<temp.size();i++)
        {
            sum+=temp[i];
            mx=max(mx,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return mx;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> M) 
    {
        int ans=INT_MIN;
        for(int i=0;i<c;i++)
        {
            vector<int> temp(r);
            for(int j=i;j<c;j++)
            {
                for(int k=0;k<r;k++)
                {
                    temp[k]+=M[k][j];
                }
                ans=max(ans,kaden(temp));
            }
        }
        return ans;
    }
};
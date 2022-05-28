class Solution{
  public:
  int smallestSumSubarray(vector<int>& a)
  {
      int sum=0,ans=INT_MAX;
      for(int i=0;i<a.size();i++)
      {
          sum=min(a[i],sum+a[i]);
          ans=min(ans,sum);
      }
      return ans;
  }
};
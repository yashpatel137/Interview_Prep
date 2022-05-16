class Solution {
  public:
    int setBits(int N) 
    {
        int ans=0;
        while(N>0)
        {
            if(N&1==1)
            {
                ans++;
            }
            N=N>>1;
        }
        return ans;
    }
};
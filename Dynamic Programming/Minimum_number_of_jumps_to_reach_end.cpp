class Solution{
  public:
    int minJumps(int arr[], int n){
        int ans=1;
        int maxjmp=arr[0];
        int step=arr[0];
        if(n==1)
        {
            return 0;
        }
        else if(arr[0]==0)
        {
            return -1;
        }
        else
        {
            for(int i=1;i<n;i++)
            {
                if(i==n-1)
                {
                    return ans;
                }
                maxjmp=max(maxjmp,i+arr[i]);
                step--;
                if(step==0)
                {
                    ans++;
                    if(i>=maxjmp)
                    {
                        return -1;
                    }
                    step=maxjmp-i;
                }
            }
        }
    }
};
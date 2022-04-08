class Solution{
  public:
    void solve(int a[],int n,int k,int currsum,int count,vector<bool> &vis, int sum,bool &ans)
    {
        if(count==k-1)
        {
            ans=true;
            return;
        }
        if(currsum>sum)
        {
            return;
        }
        if(currsum==sum)
        {
            return solve(a,n,k,0,count+1,vis,sum,ans);
            if(ans==true)
            {
                return;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                solve(a,n,k,currsum+a[i],count,vis,sum,ans);
                if(ans==true)
                {
                    return;
                }
                vis[i]=false;
            }
        }
        return;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if(k>n)
        {
            return false;
        }
        if(k==1)
        {
            return true;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        if(sum%k!=0)
        {
            return false;
        }
        vector<bool> vis(n,false);
        bool ans=false;
        solve(a,n,k,0,0,vis,sum/k,ans);
        return ans;
    }
};
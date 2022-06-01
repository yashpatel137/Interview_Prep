//Method 1
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>> vec(K+1,vector<int>(N,0));
        for(int i=1;i<=K;i++)
        {
            int mx=INT_MIN;
            for(int j=1;j<N;j++)
            {
                mx=max(mx,vec[i-1][j-1]-A[j-1]);
                vec[i][j]=max(vec[i][j-1],mx+A[j]);
            }
        }
        return vec[K][N-1];
    }
};

//Method 2
class Solution {
  public:
    
    int dp[501][2][201];
    vector<int> arr;
    
    int f(int i, bool buy, int k){
        if(i==arr.size()) return 0;
        
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        
        int ans=f(i+1,buy,k);
        
        if(buy and k)
        ans=max(ans,-arr[i]+f(i+1,false,k));
        
        if(!buy)
        ans=max(ans,arr[i]+f(i+1,true,k-1));
        
        return dp[i][buy][k]=ans;
    }
    
    int maxProfit(int k, int n, int A[]) {
        memset(dp,-1,sizeof(dp));
        arr.resize(n);
        
        for(int i=0;i<n;i++)
        arr[i]=A[i];
        
        return f(0,true,k);
    }
};
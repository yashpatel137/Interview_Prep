class Solution{
  public:
    int countMin(string str)
    {
        string str1=str;
        int n=str.size();
        int dp[n+1][n+1];
        reverse(str.begin(),str.end());
        for(int i=0;i<n+1;i++)
        {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(str[i-1]==str1[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        }
        int ans=dp[n][n];
        return n-ans;
    }
};

//Method 2
class Solution{
  public:
    int countMin(string str){
        int l,h;
        int size=str.length();
        int arr[size][size]={0};
        for(int i=1;i<size;i++)
        {
            for(l=0,h=i;h<size;l++,h++)
            {
                if(str[l]==str[h])
                {
                    arr[l][h]=arr[l+1][h-1];
                }
                else
                {
                    arr[l][h]=(min(arr[l][h-1],arr[l+1][h])+1);
                }
            }
        }
        return arr[0][size-1];
    }
};
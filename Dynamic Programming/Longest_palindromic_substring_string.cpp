class Solution {
public:
    string solve(string s1,string s2)
    {
        int size1=s1.length(),size2=s2.length();
        int dp[size1+1][size2+1];
        string ans;
        int max=0;
        for(int i=0;i<=size1;i++)
        {
            for(int j=0;j<=size2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    if(dp[i][j]>max)
                    {
                        string temp=s1.substr(i-dp[i][j],dp[i][j]);
                        string revtmp=string(temp.rbegin(),temp.rend());
                        if(temp==revtmp)
                        {
                            max=dp[i][j];
                            ans=temp;
                        }
                    }
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
    string longestPalindrome(string s) 
    {
        string rev = string(s.rbegin(),s.rend());
        return solve(s,rev);
    }
};
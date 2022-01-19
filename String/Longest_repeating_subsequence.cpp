class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.size();
		    vector<vector<int>> vec(n+1,vector<int> (n+1,0));
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=n;j++)
		        {
		            if(str[i-1]==str[j-1] && i!=j)
		            {
		                vec[i][j]=1+vec[i-1][j-1];
		            }
		            else
		            {
		                vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
		            }
		        }
		    }
		    return vec[n][n];
		}
};
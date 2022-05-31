//Method 1 
class Solution{
public:
    bool isPal(int i,int j,string s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int n,string &s,vector<int> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int mn=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPal(i,j,s))
            {
                int cost=1+solve(j+1,n,s,dp);
                mn=min(mn,cost);
            }
        }
        return dp[i]=mn;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<int> dp(n,-1);
        return solve(0,n,str,dp)-1;
    }
};

//Method 2 DP with tabulation
class Solution {
public:
    int n;
	string s;
	vector<int> cuts;
	vector<vector<int>> dp;

	bool getPalSub(int i,int j) {
		if(i>=j) return true;
		if(dp[i][j]!=-1) return dp[i][j];

		if(s[i]==s[j] && getPalSub(i+1,j-1)) dp[i][j]=1;
		else dp[i][j]=0;

		return dp[i][j];
	}

	int getPalCuts(int i) {
		if(i==n) return 0;
		if(cuts[i]!=-1) return cuts[i];

		int mn=n-i;
		for(int j=i;j<n;j++) {
			if(getPalSub(i,j)) mn= min(mn,getPalCuts(j+1)+1);
		}
		return cuts[i]=mn;
	}

	int minCut(string s) {
		n= s.length();
		this->s=s;
		dp.resize(n,vector<int>(n,-1));
		cuts.resize(n,-1);
		return getPalCuts(0)-1;
	}
};
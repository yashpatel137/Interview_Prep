//Method 1 dp iterative
class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        int n=A.size();
        unordered_set<string> h(begin(B),end(B));
        vector<bool> vec(n+1,0);
        vec[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i and !vec[i];j++)
            {
                vec[i]=vec[i] or (vec[j] and h.count(A.substr(j,i-j)));
            }
        }
        return vec[n];
    }
};

//Method 2 dp recursive
class Solution
{
public:
    unordered_set<string>st;
    int dp[1101];
    int solve(string s,int idx)
    {
        if(idx==s.size())
        {
            return 1;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        string temp="";
        for(int i=idx;i<s.size();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
            {
                if(solve(s,i+1))
                {
                    return dp[idx]=1;
                }
            }
        }
        return dp[idx]=0;
    }
    int wordBreak(string A, vector<string> &B) 
    {
        memset(dp,-1,sizeof(dp));
        for(auto x:B)
        {
            st.insert(x);
        }
        return solve(A,0);
    }
};
class Solution {
  public:
    
    bool isPal(string &str,int low, int high)
    {
        while(low<high)
        {
            if(str[low]!=str[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void solve(string &st, vector<string> tmpans, vector<vector<string>> &ans,int start, int n)
    {
        if(start>=n)
        {
            ans.push_back(tmpans);
            return;
        }
        for(int i=start;i<n;i++)
        {
            if(isPal(st,start,i))
            {
                tmpans.push_back(st.substr(start,i-start+1));
                solve(st,tmpans,ans,i+1,n);
                tmpans.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) 
    {
        vector<vector<string>> ans;
        vector<string> tmpans;
        int n=S.length();
        solve(S,tmpans,ans,0,n);
        return ans;
    }
};
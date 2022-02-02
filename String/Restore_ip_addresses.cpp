class Solution {
public:
    bool is_valid(string s)
    {
        if(s.length() > 3) 
        {
            return false;
        }
        if(s.length() <= 0 )
        { 
            return false;
        }
        if(s.size() > 1 && s[0] == '0')
        {
            return false;
        }
        int num = stoi(s);
        if(num >= 0 && num < 256) 
        {
            return true;
        }
        return false;
    }
    void solve(string &s, const string &res, int count_dot, int idx,vector<string> &ans)
    {
        if(count_dot == 0)
        {
            if(is_valid(s.substr(idx)))
            {
                ans.push_back(res + s.substr(idx));
            }
            return;
        }
        for(int i = 1; i < 4; i++)
        {
            if(s[idx] == '0')
            {
                solve(s, res + "0" + ".", count_dot - 1, idx + 1,ans);
                break; 
            }
            if( (idx + i-1 < s.size())  &&  is_valid(s.substr(idx,i)) )
            {
                solve(s, res + s.substr(idx,i) + ".", count_dot - 1, idx + i,ans);
            }
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n=s.length();
        solve(s,"",3,0,ans);
        return ans;
    }
};
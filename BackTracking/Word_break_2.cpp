class Solution{
public:
    vector<string> ans;
    void solve(vector<string> dict, string s, string temp, int i)
    {
        if(i>=s.length())
        {
            temp.pop_back();
            ans.push_back(temp);
        }
        string str;
        for(int j=i;j<s.length();j++)
        {
            str+=s[j];
            if(find(dict.begin(),dict.end(),str)!=dict.end())
            {
                solve(dict,s,temp+str+' ',j+1);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        solve(dict,s,"",0);
        return ans;
    }
};
class Solution {
public:
    void solve(string str, vector<string> &ans, map<string,bool> &mp, int rm)
    {
        if(mp[str])
        {
            return;
        }
        else
        {
            mp[str]=true;
        }
        if(rm==0)
        {
            int n=minRemoval(str);
            if(n==0)
            {
                ans.push_back(str);
            }
            return;
        }
        for(int i=0;i<str.length();i++)
        {
			string left = str.substr(0,i);
			string right = str.substr(i+1);
			solve(left+right, ans, mp, rm-1); 
		}
    }
    int minRemoval(string str)
    {
        stack<int> st;
		for(auto it:str)
        {
			if(it == '(')   
            {
                st.push(it);
            }
			else if(it == ')')
            {
				if(!st.empty() && st.top() == '(')
                {
					st.pop();
                }
				else
                {
                    st.push(it);
                }
			}
		}
		return st.size();
    }
    vector<string> removeInvalidParentheses(string s) 
    {
        int remove=minRemoval(s);
        vector<string> ans;
        map<string,bool> mp;
        solve(s,ans,mp,remove);
        return ans;
    }
};
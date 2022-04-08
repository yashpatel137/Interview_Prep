// TLE error
class Solution {
public:
    void solve(int n, int cnt, vector<vector<string>> &v, vector<string> ans, set<int> &s)
    {
        if(cnt==0)
        {
            v.push_back(ans);
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(s.count(i)==0)
            {
                ans.push_back(to_string(i));
                s.insert(i);
                solve(n,cnt-1,v,ans,s);
                s.erase(s.find(i));
                ans.pop_back();
            }
        }
        return;
    }
    string getPermutation(int n, int k) 
    {
        vector<string>ans;
        int cnt=n;
        set<int>s;
        vector<vector<string>> v;
        solve(n,cnt,v,ans,s);
        string str="";
        for(int i=0;i<n;++i)
        {
            str+=v[k-1][i];
        }
        return str;
    }
};

//Without error
class Solution {
public:
    string s;
    void helper(vector<int>& vec,vector<int>& temp,int& k,int idx)
    {
        if(idx == vec.size())
        {
            k--;
            s = "";
            if(k == 0)
            {
                for(int i = 0;i<vec.size();i++)
                {
                    s += to_string(temp[i]);
                } 
            }
            return;
        }
        if(k == 0)
        {
            return;
        }
        
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i] > 0)
            {
                temp[idx] = vec[i];
                vec[i] = -1*vec[i];
                helper(vec,temp,k,idx+1);
                vec[i] = -1*vec[i];
                temp[idx] = 0;
            }
        }
        
    }
    
    string getPermutation(int n, int k) {
        vector<int> vec(n,0);
        for(int i=1;i<=n;i++)
        {
            vec[i-1] = i;
        }
        
        vector<int> temp(n,0);
        helper(vec,temp,k,0);
        return s;
    }
};
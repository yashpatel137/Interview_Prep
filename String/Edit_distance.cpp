class Solution {
  public:
    int dpmemo(int i,int j,string s,string t,vector<vector<int>> &vec)
    {
        if(i==s.size())
        {
            return t.size()-j;
        }
        if(j==t.size())
        {
            return s.size()-i;
        }
        if(vec[i][j]!=-1)
        {
            return vec[i][j];
        }
        if(s[i]==t[j])
        {
            return vec[i][j]=dpmemo(i+1,j+1,s,t,vec);
        }
        else
        {
            int l=1+dpmemo(i,j+1,s,t,vec);
            int m=1+dpmemo(i+1,j,s,t,vec);
            int r=1+dpmemo(i+1,j+1,s,t,vec);
            return vec[i][j]=min(l,min(m,r));
        }
    }
    int editDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> vec(n,vector<int> (m,-1));
        return dpmemo(0,0,s,t,vec);
    }
};
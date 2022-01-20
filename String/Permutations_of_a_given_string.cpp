//Method 1
class Solution
{
	public:
	    void perm(string S, string ans, vector<string> &vec)
	    {
	        if(S.length()==0)
	        {
	            vec.push_back(ans);
	            return;
	        }
	        for(int i=0;i<S.length();i++)
	        {
	            char ch=S[i];
	            string l=S.substr(0,i);
	            string r=S.substr(i+1);
	            string rest=l+r;
	            perm(rest,ans+ch,vec);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> vec;
		    string ans="";
		    perm(S,ans,vec);
		    sort(vec.begin(),vec.end());
		    return vec;
		}
};

//Method 2
class Solution
{
	public:
	    void perm(string s, int l, int r,vector<string>&vec)
	    {
	        if(l==r)
	        {
	            vec.push_back(s);
	            return;
	        }
	        for(int i=l;i<=r;i++)
	        {
	            swap(s[l],s[i]);
	            perm(s,l+1,r,vec);
	            swap(s[l],s[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> vec;
		    int n=S.length();
		    perm(S,0,n-1,vec);
		    sort(vec.begin(),vec.end());
		    return vec;
		}
};
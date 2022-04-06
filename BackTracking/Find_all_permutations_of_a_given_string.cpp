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
class Solution{
  public:		
	int lps(string s) {
	    int n=s.length();
	    vector<int> vec(n);
	    vec[0]=0;
	    int i=0,j=1;
	    while(j<n)
	    {
	        if(s[i]==s[j])
	        {
	            vec[j]=i+1;
	            i++;
	            j++;
	        }
	        else
	        {
	            if(i!=0)
	            {
	                i=vec[i-1];
	            }
	            else
	            {
	                vec[j]=0;
	                j++;
	            }
	        }
	    }
	    return vec[n-1];
	}
};
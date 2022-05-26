class Solution{
public:	
	int maxSubstring(string S)
	{
	    vector<int>vec(S.length());
	    for(int i=0;i<S.length();i++)
	    {
	        if(S[i]=='1')
	        {
	            vec[i]=-1;
	        }
	        else
	        {
	            vec[i]=1;
	        }
	    }
	    int sum=0,ans=INT_MIN;
	    for(int i=0;i<vec.size();i++)
	    {
	        sum+=vec[i];
	        ans=max(ans,sum);
	        if(sum<0)
	        {
	            sum=0;
	        }
	    }
	    return ans;
	}
};
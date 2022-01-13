class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    int n=v.size();
		    int ans;
		    if(n%2==0)
		    {
		        ans=(v[n/2]+v[(n/2)-1])/2;
		    }
		    else
		    {
		        ans=v[n/2];
		    }
		    return ans;
		}
};
class Solution{
public:
	long long maxProduct(vector<int> arr, int n) {
	    long long ans=INT_MIN,pre=1,post=1;
	    for(int i=0;i<n;i++)
	    {
	        pre*=arr[i];
	        post*=arr[n-i-1];
	        ans=max(ans,max(pre,post));
	        if(pre==0)
	        {
	            pre=1;
	        }
	        if(post==0)
	        {
	            post=1;
	        }
	    }
	    return ans;
	}
};
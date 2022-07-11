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

//Method 2
class Solution{
    public:
    long long int mod=1e9+7;
    long long int findMaxProduct(vector<int>&a, int n){
        if(n==1)
        {
            return a[0];
        }
        int maxneg=INT_MIN,zeroc=0,negc=0;
        long long int prod=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                zeroc++;
               continue;
            }
            if(a[i]<0)
            {
                negc++;
                maxneg=max(maxneg,a[i]);
            }
            prod=(prod*a[i])%mod;
        }
        if(zeroc==n)
        {
            return 0;
        }
        if(negc%2!=0)
        {
            if(negc==1 and zeroc>0 and zeroc+negc==n)
            {
                return 0;
            }
            return (prod/maxneg);
        }
        return prod;
    }
};

class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    long long count=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++)
	    {
	        int n1=arr[i];
	        int l=i+1;
	        int r=n-1;
	        while(l<r)
	        {
	            int sol=n1+arr[l]+arr[r];
	            if(sol>=sum)
	            {
	                r--;
	            }
	            else
	            {
	                count+=r-l;
	                l++;
	            }
	        }
	    }
	    return count;
	}
		 

};
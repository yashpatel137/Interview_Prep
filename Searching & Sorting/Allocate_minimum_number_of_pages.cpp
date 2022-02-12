class Solution 
{
    public:
    bool possible(int arr[],int n,int m,int limit)
    {
        int curr=1,pages=0;
        for(int i=0;i<n;i++)
        {
            pages+=arr[i];
            if(arr[i]>limit)
            {
                return false;
            }
            if(pages>limit)
            {
                curr++;
                pages=arr[i];
            }
        }
        if(curr>m)
        {
            return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int low=A[0],high=0;
        int res=-1;
        if(M>N)
        {
            return -1;
        }
        for(int i=0;i<N;i++)
        {
            high+=A[i];
        }
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(possible(A,N,M,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};
class Solution{
  public:
    void merge(long long arr[],long long l,long long mid,long long r,long long &count)
    {
        long long i=l,j=mid+1,k=l,temp[r];
        while(i<=mid && j<=r)
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                count+=(mid-i+1);
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=r)
        {
            temp[k++]=arr[j++];
        }
        for(int i=l;i<=r;i++)
        {
            arr[i]=temp[i];
        }
    }
    void mergesort(long long arr[],long long l,long long r,long long &count)
    {
        if(l<r)
        {
            long long mid=(l+r)/2;
            mergesort(arr,l,mid,count);
            mergesort(arr,mid+1,r,count);
            merge(arr,l,mid,r,count);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long count=0;
        mergesort(arr,0,N-1,count);
        return count;
    }

};
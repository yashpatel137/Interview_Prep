class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long hi=0,lo=0;
        for(int i=0;i<n;i++)
        {
            if(lo<arr[i])
            {
                lo=arr[i];
            }
            hi+=arr[i];
        }
        while(lo<=hi)
        {
            long long mid=lo+(hi-lo)/2;
            long long count=0,sum=0;
            for(int i=0;i<n;i++)
            {
                if(sum+arr[i]<=mid)
                {
                    sum+=arr[i];
                }
                else
                {
                    count++;
                    sum=arr[i];
                }
            }
            if(sum>0)
            {
                count++;
            }
            if(count>k)
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return lo;
    }
};
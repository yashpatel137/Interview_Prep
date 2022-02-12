int bsearch(int a[],int n,int k)
{
    long long int count;
    sort(a,a+n);
    int lo = 1;
    int hi = a[n-1];
    while(lo <= hi) 
    {
        int mid = (lo+hi)>>1;
        count = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mid)
            {
                count = count + (a[i]-mid);
            }
        }
        if(count >= k) 
        {
            lo = mid;
        }
        else 
        {
            hi = mid-1;
        }
    }
    return lo;
}